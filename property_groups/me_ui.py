'''
Copyright (C) 2024 Ian Sloat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
'''

import bpy
from .me_data import MEPoseTracksClip, GOGICollection
from .me_stats import MotionEngineRunStatistics
from ..utils import set_select_tracks
from .. import MotionEngine as me

object_detection_classes = set()

for model in me.get_models('object_detection'):
    if 'classes' not in model[1]:
        continue
    classes = model[1]['classes']
    object_detection_classes.update(classes)

object_detection_classes = list(object_detection_classes)

object_detection_classes.sort()

obj_det_class_enum_items = []
for i in range(len(object_detection_classes)):
    c = object_detection_classes[i]
    obj_det_class_enum_items.append((c, c, f'Set detection target to {c.lower()}', i + 1))

object_detection_classes = [c.lower() for c in object_detection_classes]

try:
    obj_det_class_default = object_detection_classes.index('person') + 1
except ValueError:
    obj_det_class_default = 1

tag_dictionary_members = [e for e in me.TagDictionary.__members__]

tag_detector_cv_dict_list_items = []
for m in tag_dictionary_members:
    tag_detector_cv_dict_list_items.append((m, m, f'Set dictionary to {m}'))


def force_redraw(self, context):
    if context.area is not None:
        for region in context.area.regions:
            if region.type == "UI":
                region.tag_redraw()
    return None


def det_thresh_mode_update(self, context):
    scene = context.scene
    properties = scene.motion_engine_ui_properties
    if properties.me_ui_prop_det_thresholding_enum == "AUTO":
        properties.me_ui_prop_det_conf = 0.5
        properties.me_ui_prop_det_iou = 0.5
    return None


def det_tag_thresh_mode_update(self, context):
    scene = context.scene
    properties = scene.motion_engine_ui_properties
    if properties.me_ui_prop_det_tag_thresholding_enum == "AUTO":
        properties.me_ui_prop_det_tag_conf = 0.5
        properties.me_ui_prop_det_tag_iou = 0.5
    return None


def track_thresh_mode_update(self, context):
    scene = context.scene
    properties = scene.motion_engine_ui_properties
    if properties.me_ui_prop_track_thresholding_enum == "AUTO":
        properties.me_ui_prop_track_score = 1.4
        properties.me_ui_prop_track_reid_score = 1.0
        properties.me_ui_prop_track_dist_type = "NORM_EUCLIDEAN"
    return None


def cache_method_update(self, context):
    scene = context.scene
    properties = scene.motion_engine_ui_properties
    if properties.me_ui_prop_cache_method_enum == "AUTO":
        properties.me_ui_prop_cache_size = 256
    return None


def active_pose_update(self, context):
    scene = context.scene
    properties = scene.motion_engine_ui_properties
    current_clip = context.edit_movieclip
    clip_tracks = current_clip.tracking.tracks

    target_list = None

    for item in properties.me_ui_prop_pose_clip_collection:
        if item.clip == current_clip:
            target_list = item.pose_tracks_list
            break

    if target_list is not None:
        target = target_list[properties.me_ui_prop_active_pose_index]

        if target is not None:

            all_pose_tracks = []
            target_pose_tracks = []

            for other in target_list:
                for i in range(other.tracks):
                    track = clip_tracks.get(other.track_prefix + '.' + str(i))
                    if track is not None:
                        all_pose_tracks.append(track)

            for i in range(target.tracks):
                track = clip_tracks.get(target.track_prefix + '.' + str(i))
                if track is not None:
                    target_pose_tracks.append(track)

            set_select_tracks(all_pose_tracks, False)
            set_select_tracks(target_pose_tracks, True)

    return None


class MotionEngineUIProperties(bpy.types.PropertyGroup):
    # Executor list text
    executor_list_name = "Target execution device"
    executor_list_desc = "Model execution device"
    cpu_tooltip = "Run model on the CPU"
    cuda_tooltip = "Run model on GPU using CUDA (Recommended)"
    tensorrt_tooltip = "Run model on GPU using TensorRT. Faster than CUDA but prone to loading errors"
    id_cpu = "CPU"
    id_cuda = "CUDA"
    id_tensorrt = "TENSORRT"
    desc_cpu = "CPU"
    desc_cuda = "CUDA"
    desc_tensorrt = "TensorRT"

    # Pose model depth text
    depth_list_name = "Pose model depth"
    depth_list_desc = "Sets the depth of the pose model"
    tiny_tooltip = "Minimum depth. Has the least prediction accuracy"
    small_tooltip = "Small depth. Decent accuracy and execution speed (Recommended)"
    medium_tooltip = "Medium depth. Slower, but predictions are more stable"
    medium_tooltip_133 = "Medium depth. Decent accuracy and execution speed (Recommended)"
    large_tooltip = "Large depth. Slowest, but has the highest accuracy"
    id_tiny = "t"
    id_small = "s"
    id_medium = "m"
    id_large = "l"
    desc_tiny = "Tiny"
    desc_small = "Small"
    desc_medium = "Medium"
    desc_large = "Large"

    # Pose model precision text
    precision_list_name = "Pose model precision"
    precision_list_desc = "Sets the coordinate precision of the pose model"
    single_tooltip = "Standard precision (Recommended)"
    double_tooltip = "Double precision. Slower, but has higher accuracy"
    id_single = "SINGLE"
    id_double = "DOUBLE"
    desc_single = "Single"
    desc_double = "Double"

    # Detection model selection text
    simple_selection_list_name = "Detection model preference"
    simple_selection_list_desc = "Automatically choose the best model based on certain criteria"
    simp_det_sel_fast_tooltip = "Choose the fastest model available"
    simp_det_sel_bal_tooltip = "Choose a model that is both fast and somewhat accurate (Recommended)"
    simp_det_sel_bal_mem_tooltip = "Choose a model that is fast, accurate, and has a small memory footprint"
    simp_det_sel_accurate_tooltip = "Choose the model with the highest accuracy"
    id_simp_det_sel_fast = "FAST"
    id_simp_det_sel_bal = "BALANCED"
    id_simp_det_sel_bal_mem = "BAL_MEM"
    id_simp_det_sel_accurate = "ACCURATE"
    desc_simp_det_sel_fast = "Fast"
    desc_simp_det_sel_bal = "Balanced"
    desc_simp_det_sel_bal_mem = "Balanced memory"
    desc_simp_det_sel_accurate = "Accurate"

    # Tag model selection text
    tag_detector_type_list_name = "Tag detector type"
    tag_detector_type_list_desc = "Set the desired detection method"
    tag_detector_type_cv_tooltip = "Standard CV detector. Must specify target marker dictionary (Recommended)."
    tag_detector_type_ml_tooltip = "Machine learning based detector"
    id_tag_detector_type_cv = "CV"
    id_tag_detector_type_ml = "ML"
    desc_tag_detector_type_cv = id_tag_detector_type_cv
    desc_tag_detector_type_ml = id_tag_detector_type_ml
    tag_detector_cv_dict_list_name = "Target marker dictionary"
    tag_detector_cv_dict_list_desc = "Set the target marker dictionary"
    tag_detector_cv_resample_toggle_name = "Resample input"
    tag_detector_cv_resample_toggle_desc = ("Resample detection to improve subpixel accuracy. "
                                            "Disable if having issues with tracking")
    tag_detector_ml_model_sel_list_name = "Tag model preference"
    tag_detector_ml_model_sel_list_desc = "Automatically choose the best model based on certain criteria"
    tag_det_ml_sel_fast_tooltip = "Choose the fastest model available"
    tag_det_ml_sel_bal_tooltip = "Choose a model that is both fast and somewhat accurate (Recommended)"
    tag_det_ml_sel_bal_mem_tooltip = "Choose a model that is fast, accurate, and has a small memory footprint"
    tag_det_ml_sel_accurate_tooltip = "Choose the model with the highest accuracy"
    id_tag_det_ml_sel_fast = "FAST"
    id_tag_det_ml_sel_bal = "BALANCED"
    id_tag_det_ml_sel_bal_mem = "BAL_MEM"
    id_tag_det_ml_sel_accurate = "ACCURATE"
    desc_tag_det_ml_sel_fast = "Fast"
    desc_tag_det_ml_sel_bal = "Balanced"
    desc_tag_det_ml_sel_bal_mem = "Balanced memory"
    desc_tag_det_ml_sel_accurate = "Accurate"

    me_ui_redraw_prop: bpy.props.BoolProperty(
        name="Update property",
        description="Hidden prop",
        default=False,
        update=force_redraw
    )
    me_ui_prop_remove_poses: bpy.props.BoolProperty(
        name="Remove existing poses",
        description="Delete existing poses on new analysis",
        default=False
    )
    me_ui_tag_detector_cv_resample_toggle_prop: bpy.props.BoolProperty(
        name=tag_detector_cv_resample_toggle_name,
        description=tag_detector_cv_resample_toggle_desc,
        default=False
    )
    me_ui_tag_detector_cv_dict_list_enum: bpy.props.EnumProperty(
        name=tag_detector_cv_dict_list_name,
        description=tag_detector_cv_dict_list_desc,
        items=tag_detector_cv_dict_list_items
    )
    me_ui_prop_tag_detector_type_enum: bpy.props.EnumProperty(
        name=tag_detector_type_list_name,
        description=tag_detector_type_list_desc,
        items=[
            (id_tag_detector_type_cv, desc_tag_detector_type_cv, tag_detector_type_cv_tooltip, 1),
            (id_tag_detector_type_ml, desc_tag_detector_type_ml, tag_detector_type_ml_tooltip, 2),
        ]
    )
    me_ui_prop_tag_detector_ml_model_sel_enum: bpy.props.EnumProperty(
        name=tag_detector_ml_model_sel_list_name,
        description=tag_detector_ml_model_sel_list_desc,
        items=[
            (id_tag_det_ml_sel_fast, desc_tag_det_ml_sel_fast, tag_det_ml_sel_fast_tooltip, 1),
            (id_tag_det_ml_sel_bal, desc_tag_det_ml_sel_bal, tag_det_ml_sel_bal_tooltip, 2),
            (id_tag_det_ml_sel_bal_mem, desc_tag_det_ml_sel_bal_mem, tag_det_ml_sel_bal_mem_tooltip, 3),
            (id_tag_det_ml_sel_accurate, desc_tag_det_ml_sel_accurate, tag_det_ml_sel_accurate_tooltip, 4),
        ],
        default=2
    )
    me_ui_prop_exe_tag_detector_ml_enum: bpy.props.EnumProperty(
        name=executor_list_name,
        description=executor_list_desc,
        items=[
            (id_cpu, desc_cpu, cpu_tooltip, 1),
            (id_cuda, desc_cuda, cuda_tooltip, 2),
        ],
        default=2
    )
    me_ui_prop_exe_det_enum: bpy.props.EnumProperty(
        name=executor_list_name,
        description=executor_list_desc,
        items=[
            (id_cpu, desc_cpu, cpu_tooltip, 1),
            (id_cuda, desc_cuda, cuda_tooltip, 2),
        ],
        default=2
    )
    me_ui_prop_exe_pose_enum: bpy.props.EnumProperty(
        name=executor_list_name,
        description=executor_list_desc,
        items=[
            (id_cpu, desc_cpu, cpu_tooltip, 1),
            (id_cuda, desc_cuda, cuda_tooltip, 2),
            (id_tensorrt, desc_tensorrt, tensorrt_tooltip, 3),
        ],
        default=2
    )
    me_ui_prop_exe_track_enum: bpy.props.EnumProperty(
        name=executor_list_name,
        description=executor_list_desc,
        items=[
            (id_cpu, desc_cpu, cpu_tooltip, 1),
            (id_cuda, desc_cuda, cuda_tooltip, 2),
        ],
        default=2
    )
    me_ui_prop_exe_det_tag_enum: bpy.props.EnumProperty(
        name=executor_list_name,
        description=executor_list_desc,
        items=[
            (id_cpu, desc_cpu, cpu_tooltip, 1),
            (id_cuda, desc_cuda, cuda_tooltip, 2),
        ],
        default=2
    )
    me_ui_prop_det_batch_size: bpy.props.IntProperty(
        name="Batch size for detection model",
        description="Sets the amount of frames to be processed by the detection model at any given time",
        default=32,
        min=1,
        max=256
    )
    me_ui_prop_pose_batch_size: bpy.props.IntProperty(
        name="Batch size for pose model",
        description="Sets the amount of detections to be processed by the pose model at any given time",
        default=32,
        min=1,
        max=256
    )
    me_ui_prop_det_conf: bpy.props.FloatProperty(
        name="Confidence threshold",
        description="Sets the minimum acceptable confidence score for detections",
        default=0.5,
        min=0,
        max=1
    )
    me_ui_prop_det_iou: bpy.props.FloatProperty(
        name="IoU threshold",
        description="Sets the maximum acceptable overlap between detections. Non-maximum suppression will be used on "
                    "boxes with overlap values higher than this",
        default=0.5,
        min=0,
        max=1
    )
    me_ui_prop_det_tag_conf: bpy.props.FloatProperty(
        name="Confidence threshold",
        description="Sets the minimum acceptable confidence score for detections",
        default=0.5,
        min=0,
        max=1
    )
    me_ui_prop_det_tag_iou: bpy.props.FloatProperty(
        name="IoU threshold",
        description="Sets the maximum acceptable overlap between detections. Non-maximum suppression will be used on "
                    "boxes with overlap values higher than this",
        default=0.5,
        min=0,
        max=1
    )
    me_ui_prop_track_score: bpy.props.FloatProperty(
        name="Distance threshold",
        description="Sets the maximum feature distance for tracking candidates",
        default=1.4,
        min=0
    )
    me_ui_prop_track_reid_score: bpy.props.FloatProperty(
        name="ReID threshold",
        description="Sets the maximum feature distance for reID candidates",
        default=1.0,
        min=0
    )
    me_ui_prop_track_dist_type: bpy.props.EnumProperty(
        name="Distance type",
        description="Equation to use for feature distance calculations",
        items=[
            ("EUCLIDEAN", "L2 norm", "Euclidean L2 norm", 1),
            ("NORM_EUCLIDEAN", "Norm L2 norm", "Normalized Euclidean L2 norm (Recommended)", 2),
        ],
        default=2
    )
    me_ui_prop_det_size_enum: bpy.props.EnumProperty(
        name="Input size",
        description="Sets the desired input size. A higher input size can help if there aren't any detections on "
                    "certain frames",
        items=[
            ("320", "320", "Set input size to 320x320 (Recommended)"),
            ("640", "640", "Set input size to 640x640"),
        ],
        default="320",
        update=det_thresh_mode_update
    )
    me_ui_prop_pose_keypoints_enum: bpy.props.EnumProperty(
        name="Pose keypoints",
        description="Sets the number of keypoints to detect per pose",
        items=[
            ("17", "17", "Standard set"),
            ("26", "26", "Extended set. Includes points for feet, neck, pelvis, and head axis (Recommended)"),
            ("133", "133", "Detailed set. Same as standard but includes additional points for face, hands, and feet"),
        ],
        default="26"
    )
    me_ui_prop_pose_depth17_enum: bpy.props.EnumProperty(
        name=depth_list_name,
        description=depth_list_desc,
        items=[
            (id_tiny, desc_tiny, tiny_tooltip, 1),
            (id_small, desc_small, small_tooltip, 2),
            (id_medium, desc_medium, medium_tooltip, 3),
            (id_large, desc_large, large_tooltip, 4),
        ],
        default=2
    )
    me_ui_prop_pose_depth26_enum: bpy.props.EnumProperty(
        name=depth_list_name,
        description=depth_list_desc,
        items=[
            (id_tiny, desc_tiny, tiny_tooltip, 1),
            (id_small, desc_small, small_tooltip, 2),
            (id_medium, desc_medium, medium_tooltip, 3),
            (id_large, desc_large, large_tooltip, 4),
        ],
        default=2
    )
    me_ui_prop_pose_depth133_enum: bpy.props.EnumProperty(
        name=depth_list_name,
        description=depth_list_desc,
        items=[
            (id_medium, desc_medium, medium_tooltip_133, 3),
            (id_large, desc_large, large_tooltip, 4),
        ],
        default=3
    )
    me_ui_prop_pose_precision17m_enum: bpy.props.EnumProperty(
        name=precision_list_name,
        description=precision_list_desc,
        items=[
            (id_single, desc_single, single_tooltip, 1),
            (id_double, desc_double, double_tooltip, 2),
        ],
        default=1
    )
    me_ui_prop_pose_precision17l_enum: bpy.props.EnumProperty(
        name=precision_list_name,
        description=precision_list_desc,
        items=[
            (id_single, desc_single, single_tooltip, 1),
            (id_double, desc_double, double_tooltip, 2),
        ],
        default=1
    )
    me_ui_prop_pose_precision26m_enum: bpy.props.EnumProperty(
        name=precision_list_name,
        description=precision_list_desc,
        items=[
            (id_single, desc_single, single_tooltip, 1),
            (id_double, desc_double, double_tooltip, 2),
        ],
        default=1
    )
    me_ui_prop_pose_precision26l_enum: bpy.props.EnumProperty(
        name=precision_list_name,
        description=precision_list_desc,
        items=[
            (id_single, desc_single, single_tooltip, 1),
            (id_double, desc_double, double_tooltip, 2),
        ],
        default=1
    )
    me_ui_prop_pose_precision133l_enum: bpy.props.EnumProperty(
        name=precision_list_name,
        description=precision_list_desc,
        items=[
            (id_single, desc_single, single_tooltip, 1),
            (id_double, desc_double, double_tooltip, 2),
        ],
        default=1
    )
    me_ui_prop_det_simple_sel_enum: bpy.props.EnumProperty(
        name=simple_selection_list_name,
        description=simple_selection_list_desc,
        items=[
            (id_simp_det_sel_fast, desc_simp_det_sel_fast, simp_det_sel_fast_tooltip, 1),
            (id_simp_det_sel_bal, desc_simp_det_sel_bal, simp_det_sel_bal_tooltip, 2),
            (id_simp_det_sel_bal_mem, desc_simp_det_sel_bal_mem, simp_det_sel_bal_mem_tooltip, 3),
            (id_simp_det_sel_accurate, desc_simp_det_sel_accurate, simp_det_sel_accurate_tooltip, 4),
        ],
        default=2
    )
    me_ui_prop_det_tag_simple_sel_enum: bpy.props.EnumProperty(
        name=simple_selection_list_name,
        description=simple_selection_list_desc,
        items=[
            (id_simp_det_sel_fast, desc_simp_det_sel_fast, simp_det_sel_fast_tooltip, 1),
            (id_simp_det_sel_bal, desc_simp_det_sel_bal, simp_det_sel_bal_tooltip, 2),
            (id_simp_det_sel_bal_mem, desc_simp_det_sel_bal_mem, simp_det_sel_bal_mem_tooltip, 3),
            (id_simp_det_sel_accurate, desc_simp_det_sel_accurate, simp_det_sel_accurate_tooltip, 4),
        ],
        default=2
    )
    me_ui_prop_det_class_enum: bpy.props.EnumProperty(
        name="Target",
        description="Set the target object",
        items=obj_det_class_enum_items,
        default=obj_det_class_default
    )
    me_ui_prop_det_thresholding_enum: bpy.props.EnumProperty(
        name="Thresholding mode",
        description="Set threshold values automatically or manually",
        items=[
            ("AUTO", "Auto", "Set threshold values automatically (Recommended)"),
            ("MANUAL", "Manual", "Set threshold values manually"),
        ],
        default="AUTO",
        update=det_thresh_mode_update
    )
    me_ui_prop_track_thresholding_enum: bpy.props.EnumProperty(
        name="Thresholding mode",
        description="Set threshold values automatically or manually",
        items=[
            ("AUTO", "Auto", "Set threshold values automatically (Recommended)"),
            ("MANUAL", "Manual", "Set threshold values manually"),
        ],
        default="AUTO",
        update=track_thresh_mode_update
    )
    me_ui_prop_det_tag_thresholding_enum: bpy.props.EnumProperty(
        name="Thresholding mode",
        description="Set threshold values automatically or manually",
        items=[
            ("AUTO", "Auto", "Set threshold values automatically (Recommended)"),
            ("MANUAL", "Manual", "Set threshold values manually"),
        ],
        default="AUTO",
        update=det_tag_thresh_mode_update
    )
    me_ui_prop_cache_method_enum: bpy.props.EnumProperty(
        name="Cache configuration mode",
        description="Lets you decide whether to set image cache size automatically or manually",
        items=[
            ("AUTO", "Auto", "Set image cache automatically (Recommended)"),
            ("MANUAL", "Manual", "Set image cache size manually"),
        ],
        default="AUTO",
        update=cache_method_update
    )
    me_ui_prop_cache_size: bpy.props.IntProperty(
        name="Pre-inference cache size",
        description="Number of frames to load into memory prior to inference",
        default=256,
        min=1,
        max=1024
    )
    me_ui_prop_stats_collection: bpy.props.CollectionProperty(type=MotionEngineRunStatistics)
    me_ui_prop_pose_clip_collection: bpy.props.CollectionProperty(type=MEPoseTracksClip)
    me_ui_prop_active_pose_index: bpy.props.IntProperty(
        name="Active Pose Index",
        description="Active pose in the pose tracks list",
        update=active_pose_update
    )

    me_ui_prop_rigging_avg_locked_axis: bpy.props.IntProperty(
        min=0,
        max=2,
        default=0
    )

    # Placeholder property. Must always remain empty.
    me_ui_prop_pose_empty_clip: bpy.props.PointerProperty(type=MEPoseTracksClip)

    gen_objs: bpy.props.PointerProperty(type=GOGICollection)

    def get_clip_pose_tracks(self, clip):
        for element in self.me_ui_prop_pose_clip_collection:
            if element.clip == clip:
                return element
        return None


CLASSES = [
    MotionEngineUIProperties
]
