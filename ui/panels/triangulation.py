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
from ... import global_vars


class TrackingView3DUIPanel(bpy.types.Panel):
    bl_label = "Tracking"
    bl_idname = "MOTIONENGINE_TRACKING_VIEW3D_PT_panel"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "MotionEngine"
    bl_context = "objectmode"

    display_priority = 1

    def draw(self, context):
        layout = self.layout
        scene = context.scene
        properties = scene.motion_engine_ui_properties
        ui_lock = global_vars.ui_lock_state

        layout.enabled = not ui_lock

        box = layout.box()
        box = box.column(align=True)
        row = box.row()
        row.label(text='Anchor view:')
        row = box.row()
        row.prop(properties, 'anchor_cam_selection', text='')

        column = layout.column(align=True)
        row = column.row(align=True)

        row.operator("motionengine.solve_cameras_operator")

        row = column.row(align=True)

        row.prop(properties, 'solution_scale')

        row = layout.row()

        row.operator("motionengine.triangulate_points_operator")


class PoseSelectedView3DUIPanel(bpy.types.Panel):
    bl_label = "Selected Pose"
    bl_idname = "MOTIONENGINE_POSE_SELECTED_VIEW3D_PT_panel"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "MotionEngine"
    bl_context = "objectmode"

    display_priority = 2

    @classmethod
    def poll(cls, context):
        active_obj = context.active_object
        if active_obj is None:
            return False
        req_attr = ['pose_source', 'pose_name', 'joint_id', 'cam_solution_id']
        return all(attr in active_obj.keys() for attr in req_attr)

    def draw(self, context):
        layout = self.layout

        active_obj = context.active_object

        pose_source = active_obj['pose_source']
        pose_name = active_obj['pose_name']
        joint_id = active_obj['joint_id']
        cam_solution_id = active_obj['cam_solution_id']

        box = layout.box()
        box = box.column()
        row = box.row()
        row.label(text=pose_name, icon='ARMATURE_DATA')
        row = box.row()
        row.label(text=f'Source: {pose_source.capitalize()}')
        row = box.row()
        row.label(text=f'Active ID: {joint_id}')

        row = layout.row()
        row.operator("motionengine.generate_armature_operator")


class ArmatureSelectedView3DUIPanel(bpy.types.Panel):
    bl_label = "Selected Armature"
    bl_idname = "MOTIONENGINE_ARMATURE_SELECTED_VIEW3D_PT_panel"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "MotionEngine"
    bl_context = "objectmode"

    display_priority = 3

    @classmethod
    def poll(cls, context):
        active_obj = context.active_object
        if active_obj is None:
            return False
        req_attr = ['pose_source', 'pose_name', 'cam_solution_id']
        return (all(attr in active_obj.keys() for attr in req_attr) and
                active_obj.type == 'ARMATURE')

    def draw(self, context):
        layout = self.layout

        active_obj = context.active_object

        pose_source = active_obj['pose_source']
        pose_name = active_obj['pose_name']
        cam_solution_id = active_obj['cam_solution_id']

        box = layout.box()
        box = box.column()
        row = box.row()
        row.label(text=pose_name, icon='ARMATURE_DATA')
        row = box.row()
        row.label(text=f'Source: {pose_source.capitalize()}')

        row = layout.row()
        row.operator("motionengine.bake_animation_operator")


CLASSES = [
    TrackingView3DUIPanel,
    PoseSelectedView3DUIPanel,
    ArmatureSelectedView3DUIPanel
]
