/*
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

----------------------------------------------------------------------

Blender DNA and RNA wrapper classes for use in pybind functions.
Adds low level memory access to blender.
*/

#pragma once

#include <string>
#include "generated/blender_types.hpp"

void set_compatibility_mode(BlenderVersion version);

BlenderVersion get_compatability_mode();

class BlenderDataWrapper {
public:
	BlenderDataWrapper() : data_ptr(nullptr) {};
	BlenderDataWrapper(void* data_ptr) : data_ptr(data_ptr) {};
	bool is_null() const { return data_ptr == nullptr; };
protected:
	void* data_ptr;
};

// Blender DNA enums

enum TrackFlags {
	TRACK_SELECT = 1,
	TRACK_HAS_BUNDLE = (1 << 1),
	TRACK_DISABLE_RED = (1 << 2),
	TRACK_DISABLE_GREEN = (1 << 3),
	TRACK_DISABLE_BLUE = (1 << 4),
	TRACK_HIDDEN = (1 << 5),
	TRACK_LOCKED = (1 << 6),
	TRACK_CUSTOMCOLOR = (1 << 7),
	TRACK_USE_2D_STAB = (1 << 8),
	TRACK_PREVIEW_GRAYSCALE = (1 << 9),
	TRACK_DOPE_SEL = (1 << 10),
	TRACK_PREVIEW_ALPHA = (1 << 11),
	TRACK_USE_2D_STAB_ROT = (1 << 12),
};

enum ObjectType {
	OB_EMPTY = 0,
	OB_MESH = 1,
	/** Curve object is still used but replaced by "Curves" for the future (see #95355). */
	OB_CURVES_LEGACY = 2,
	OB_SURF = 3,
	OB_FONT = 4,
	OB_MBALL = 5,
	OB_LAMP = 10,
	OB_CAMERA = 11,
	OB_SPEAKER = 12,
	OB_LIGHTPROBE = 13,
	OB_LATTICE = 22,
	OB_ARMATURE = 25,
	OB_GPENCIL_LEGACY = 26,
	OB_CURVES = 27,
	OB_POINTCLOUD = 28,
	OB_VOLUME = 29,
	OB_GREASE_PENCIL = 30,
	OB_TYPE_MAX,
};

enum EmptyDrawtype {
	OB_ARROWS = 1,
	OB_PLAINAXES = 2,
	OB_CIRCLE = 3,
	OB_SINGLE_ARROW = 4,
	OB_CUBE = 5,
	OB_EMPTY_SPHERE = 6,
	OB_EMPTY_CONE = 7,
	OB_EMPTY_IMAGE = 8,
};

enum CameraTypes {
	CAM_PERSP = 0,
	CAM_ORTHO = 1,
	CAM_PANO = 2,
};

enum CameraSensorFit {
	CAMERA_SENSOR_FIT_AUTO = 0,
	CAMERA_SENSOR_FIT_HOR = 1,
	CAMERA_SENSOR_FIT_VERT = 2,
};

enum CameraDOFFlag {
	CAM_DOF_ENABLED = (1 << 0),
};

enum CameraFlags {
	CAM_SHOWLIMITS = (1 << 0),
	CAM_SHOWMIST = (1 << 1),
	CAM_SHOWPASSEPARTOUT = (1 << 2),
	CAM_SHOW_SAFE_MARGINS = (1 << 3),
	CAM_SHOWNAME = (1 << 4),
	CAM_ANGLETOGGLE = (1 << 5),
	CAM_DS_EXPAND = (1 << 6),
	CAM_SHOWSENSOR = (1 << 8),
	CAM_SHOW_SAFE_CENTER = (1 << 9),
	CAM_SHOW_BG_IMAGE = (1 << 10),
};

enum CameraBGImageFlags {
	CAM_BGIMG_FLAG_EXPANDED = (1 << 1),
	CAM_BGIMG_FLAG_CAMERACLIP = (1 << 2),
	CAM_BGIMG_FLAG_DISABLED = (1 << 3),
	CAM_BGIMG_FLAG_FOREGROUND = (1 << 4),
	CAM_BGIMG_FLAG_CAMERA_ASPECT = (1 << 5),
	CAM_BGIMG_FLAG_CAMERA_CROP = (1 << 6),
	CAM_BGIMG_FLAG_FLIP_X = (1 << 7),
	CAM_BGIMG_FLAG_FLIP_Y = (1 << 8),
};

enum CameraBGImageSources {
	CAM_BGIMG_SOURCE_IMAGE = 0,
	CAM_BGIMG_SOURCE_MOVIE = 1,
};

enum MCUserRenderSize {
	MCLIP_PROXY_RENDER_SIZE_FULL = 0,
	MCLIP_PROXY_RENDER_SIZE_25 = 1,
	MCLIP_PROXY_RENDER_SIZE_50 = 2,
	MCLIP_PROXY_RENDER_SIZE_75 = 3,
	MCLIP_PROXY_RENDER_SIZE_100 = 4,
};

enum MCUserRenderFlags {
	MCLIP_PROXY_RENDER_UNDISTORT = 1,
	MCLIP_PROXY_RENDER_USE_FALLBACK_RENDER = 2,
};

// Blender DNA wrappers
class Library;
class AssetMetaData;
class IDProperty;
class IDOverrideLibrary;
class NlaTrack;
class NlaStrip;
class ChannelDriver;
class AnimOverride;
class BezTriple;
class FPoint;
class FCurve;
class AnimData;
class ThemeWireColor;
class bGPdata;
class bConstraintChannel;
class bActionChannel;
class bActionGroup;
class bAction;
class bPose;
class bAnimVizSettings;
class bMotionPath;
class bFaceMap;
class DrawDataList;
class Ipo;
class MovieTracking;
class MovieTrackingSettings;
class MovieTrackingCamera;
class MovieTrackingReconstruction;
class MovieTrackingStabilization;
class MovieTrackingTrack;
class MovieTrackingPlaneTrack;
class MovieTrackingStats;
class MovieTrackingDopesheet;
class MovieTrackingObject;
class MovieTrackingMarker;
class MovieClipProxy;
class ColorManagedColorspaceSettings;
class MovieClip_Runtime;
class MovieClipUser;
class MovieClip;
class Material;
class ModifierData;
class GpencilModifierData;
class ShaderFxData;
class PartDeflect;
class SoftBody;
class Collection;
class FluidsimSettings;
class RigidBodyOb;
class RigidBodyCon;
class ImageUser;
class PreviewImage;
class ObjectLineArt;
class Object_Rumtime;
class Object;
class CameraBGImage;
class Camera;
class RenderData;
class Scene;

template <typename T>
class ListBase : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	T first() const { return T(reinterpret_cast<ListBase2_93_0*>(data_ptr)->first); }
	T last() const { return T(reinterpret_cast<ListBase2_93_0*>(data_ptr)->last); }
};

template <typename T>
class ID : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	T next() const;
	T prev() const;
	ID newid() const;
	Library lib() const;
	AssetMetaData asset_data() const;
	std::string name() const;
	short flag() const;
	int tag() const;
	int us() const;
	int icon_id() const;
	unsigned int recalc() const;
	unsigned int session_uuid() const;
	IDProperty properties() const;
	IDOverrideLibrary override_library() const;
	ID orig_id() const;
};

class Library : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class AssetMetaData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class IDProperty : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class IDOverrideLibrary : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

// Each DNA and RNA struct has autogenerated subtypes for specific blender versions. These macros must include each
// subtype in a if/else if statement. If not done properly, it can result in memory alignment issues and crashes.
// 
// All wrapper classes will have macros for their function definitions. Most of them can be found in bpy_types.cpp
#define ID_BASE_RETURN_BODY(A, B, C) \
	if (get_compatability_mode() < BlenderVersion::VER_3_0_0) \
		return A ( B reinterpret_cast<ID2_93_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_2_0) \
		return A ( B reinterpret_cast<ID3_0_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_4_0) \
		return A ( B reinterpret_cast<ID3_2_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_4_1_0) \
		return A ( B reinterpret_cast<ID3_4_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_4_2_0) \
		return A ( B reinterpret_cast<ID4_1_0*>(data_ptr)-> C); \
	return A ( B reinterpret_cast<ID4_2_0*>(data_ptr)-> C);

#define ID_RETURN_AS(T, M) ID_BASE_RETURN_BODY(T,, M)
#define ID_RETURN(M) ID_BASE_RETURN_BODY(,, M)

template <typename T>
T ID<T>::next() const { ID_RETURN_AS(T, next) }

template <typename T>
T ID<T>::prev() const { ID_RETURN_AS(T, prev) }

template <typename T>
ID<T> ID<T>::newid() const { ID_RETURN_AS(ID<T>, newid) }

template <typename T>
Library ID<T>::lib() const { ID_RETURN_AS(Library, lib) }

template <typename T>
AssetMetaData ID<T>::asset_data() const { ID_RETURN_AS(AssetMetaData, asset_data) }

template <typename T>
std::string ID<T>::name() const { ID_RETURN_AS(std::string, name) }

template <typename T>
short ID<T>::flag() const { ID_RETURN(flag) }

template <typename T>
int ID<T>::tag() const { ID_RETURN(tag) }

template <typename T>
int ID<T>::us() const { ID_RETURN(us) }

template <typename T>
int ID<T>::icon_id() const { ID_RETURN(icon_id) }

template <typename T>
unsigned int ID<T>::recalc() const { ID_RETURN(recalc) }

template <typename T>
unsigned int ID<T>::session_uuid() const { ID_RETURN(session_uuid) }

template <typename T>
IDProperty ID<T>::properties() const { ID_RETURN_AS(IDProperty, properties) }

template <typename T>
IDOverrideLibrary ID<T>::override_library() const { ID_RETURN_AS(IDOverrideLibrary, override_library) }

template <typename T>
ID<T> ID<T>::orig_id() const { ID_RETURN_AS(ID<T>, orig_id) }

class NlaTrack : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class NlaStrip : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ChannelDriver : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class AnimOverride : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

typedef float(*BezTripleVecs)[3];

class BezTriple : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	BezTripleVecs vec() const;
	float& tilt() const;
	float& weight() const;
	float& radius() const;
	char& ipo() const;
	uint8_t& h1() const;
	uint8_t& h2() const;
	uint8_t& f1() const;
	uint8_t& f2() const;
	uint8_t& f3() const;
	char& hide() const;
	char& easing() const;
	float& back() const;
	float& amplitude() const;
	float& period() const;
	char& auto_handle_type() const;
};

class FPoint : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	float* vec() const;
	int& flag() const;
};

class FCurve : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	FCurve next() const;
	FCurve prev() const;
	bActionGroup grp() const;
	ChannelDriver driver() const;
	// add modifiers when type is identified
	BezTriple bezt(size_t idx) const;
	FPoint fpt(size_t idx) const;
	unsigned int totvert() const;
	int& active_keyframe_index() const;
	float curval() const;
	short& flag() const;
	short& extend() const;
	char& auto_smoothing() const;
	int& color_mode() const;
	float* color() const;
	float prev_norm_factor() const;
	float prev_offset() const;
};

class PreviewImage : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bConstraintChannel : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	bConstraintChannel next() const;
	bConstraintChannel prev() const;
	Ipo ipo() const;
	short& flag() const;
	std::string name() const;
};

class bActionChannel : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	bActionChannel next() const;
	bActionChannel prev() const;
	bActionGroup grp() const;
	Ipo ipo() const;
	ListBase<bConstraintChannel> constraintChannels() const;
	int& flag() const;
	std::string name() const;
	int& temp() const;
};

class bActionGroup : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	bActionGroup next() const;
	bActionGroup prev() const;
	ListBase<bActionChannel> channels() const;
	int& flag() const;
	int& customCol() const;
	std::string name() const;
	ThemeWireColor cs() const;
};

class bAction : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<bAction> id() const;
	ListBase<FCurve> curves() const;
	ListBase<bActionGroup> groups() const;
	// Add markers when type is determined
	int& flag() const;
	int& active_marker() const;
	int idroot() const;
	PreviewImage preview() const;
};

class AnimData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	bAction action() const;
	bAction tmpact() const;
	ListBase<NlaTrack> nla_tracks() const;
	NlaTrack act_track() const;
	NlaStrip actstrip() const;
	ListBase<ChannelDriver> drivers() const;
	ListBase<AnimOverride> overrides() const;
	// There are more member vars in AnimData, but they may not be necessary
};

class ThemeWireColor : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bGPdata : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bPose : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bAnimVizSettings : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bMotionPath : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class bFaceMap : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class DrawDataList : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class Ipo : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingSettings : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingCamera : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	short& distortion_model() const;
	float& sensor_width() const;
	float& pixel_aspect() const;
	float& focal() const;
	short& units() const;
	float& k1() const;
	float& k2() const;
	float& k3() const;
	float& division_k1() const;
	float& division_k2() const;
	float& nuke_k1() const;
	float& nuke_k2() const;
	float& brown_k1() const;
	float& brown_k2() const;
	float& brown_k3() const;
	float& brown_k4() const;
	float& brown_p1() const;
	float& brown_p2() const;
};

typedef float(*Corners)[2];

class MovieTrackingMarker : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	float *pos() const;
	Corners pattern_corners() const;
	float *search_min() const;
	float *search_max() const;
	int &framenr() const;
	int &flag() const;
};

class MovieTrackingTrack : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	MovieTrackingTrack next() const;
	MovieTrackingTrack prev() const;
	const std::string name() const;
	float* offset() const;
	int& markersnr() const;
	MovieTrackingMarker marker(size_t idx) const;
	MovieTrackingMarker find_frame(int frame, bool exact = true) const;
	float* bundle_pos() const;
	float& error() const;
	int& flag() const;
	int& pat_flag() const;
	int& search_flag() const;
	float* color() const;
	short& frames_limit() const;
	short& margin() const;
	short& pattern_match() const;
	short& motion_model() const;
	int& algorithm_flag() const;
	float& minimum_correlation() const;
	bGPdata gpd() const;
	float& weight() const;
	float& weight_stab() const;
private:
	MovieTrackingMarker tracking_marker_get(int framenr) const;
};

class MovieTrackingPlaneTrack : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingReconstruction : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingStabilization : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingObject : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	MovieTrackingObject next() const;
	MovieTrackingObject prev() const;
	const std::string name() const;
	int &flag() const;
	float &scale() const;
	ListBase<MovieTrackingTrack> tracks() const;
	ListBase<MovieTrackingPlaneTrack> plane_tracks() const;
	MovieTrackingReconstruction reconstruction() const;
	int &keyframe1() const;
	int &keyframe2() const;
};

class MovieTrackingStats : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTrackingDopesheet : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieTracking : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	MovieTrackingSettings settings() const;
	MovieTrackingCamera camera() const;
	ListBase<MovieTrackingTrack> tracks() const;
	ListBase<MovieTrackingPlaneTrack> plane_tracks() const;
	MovieTrackingReconstruction reconstruction() const;
	MovieTrackingStabilization stabilization() const;
	MovieTrackingTrack active_track() const;
	MovieTrackingPlaneTrack active_plane_track() const;
	ListBase<MovieTrackingObject> objects() const;
	const int objectnr() const;
	const int tot_objects() const;
	MovieTrackingStats stats() const;
	MovieTrackingDopesheet dopesheet();
};

class MovieClipProxy : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ColorManagedColorspaceSettings : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieClip_Runtime : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MovieClipUser : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	int& framenr() const;
	short& render_size() const;
	short& render_flag() const;
};

class MovieClip : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<MovieClip> id() const;
	AnimData anim_data() const;
	const std::string filepath() const;
	int source() const;
	int *last_size() const;
	float aspect_x() const;
	float aspect_y() const;
	bGPdata grease_pencil_data() const;
	MovieTracking tracking() const;
	int flag() const;
	int length() const;
	int &start_frame() const;
	int &frame_offset() const;
	ColorManagedColorspaceSettings colorspace_settings() const;
	MovieClip_Runtime runtime() const;
};

class Material : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ModifierData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class GpencilModifierData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ShaderFxData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class PartDeflect : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class SoftBody : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class Collection : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<Collection> id() const;
};

class FluidsimSettings : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class RigidBodyOb : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class RigidBodyCon : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ImageUser : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class ObjectLineArt : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class Object_Rumtime : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
};

class MaterialSlot {
public:
	MaterialSlot(void** materials, char* matbits, size_t mat_idx) : materials(materials), matbits(matbits), mat_idx(mat_idx) {}
	Material material() const;
	bool is_linked() const;
private:
	void** materials;
	char* matbits;
	size_t mat_idx;
};

class MaterialSlotArray {
public:
	MaterialSlotArray(void** materials, char* matbits, size_t totcol) : materials(materials), matbits(matbits), totcol(totcol) {}
	size_t size() const;
	MaterialSlot operator[](const size_t idx) const;
private:
	void** materials;
	char* matbits;
	size_t totcol;
};

// There is an issue with the parser in gen_headers.py. Not all Object variants are present
// UPDATE: resolved. Replace headers when possible

#define OBJECT_BASE_RETURN_BODY_TO_3_4_0(A, B, C) \
	if (get_compatability_mode() < BlenderVersion::VER_2_93_4) \
		return A ( B reinterpret_cast<Object2_93_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_0_0) \
		return A ( B reinterpret_cast<Object2_93_4*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_2_0) \
		return A ( B reinterpret_cast<Object3_0_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_3_0) \
		return A ( B reinterpret_cast<Object3_2_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_3_4_0) \
		return A ( B reinterpret_cast<Object3_3_0*>(data_ptr)-> C);

#define OBJECT_BASE_RETURN_BODY_POST_3_4_0(A, B, C) \
	else if (get_compatability_mode() < BlenderVersion::VER_3_6_0) \
		return A ( B reinterpret_cast<Object3_4_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_4_0_0) \
		return A ( B reinterpret_cast<Object3_6_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_4_1_0) \
		return A ( B reinterpret_cast<Object4_0_0*>(data_ptr)-> C); \
	else if (get_compatability_mode() < BlenderVersion::VER_4_2_0) \
		return A ( B reinterpret_cast<Object4_1_0*>(data_ptr)-> C);

#define OBJECT_BASE_RETURN_BODY_POST_4_2_0(A, B, C) \
	return A ( B reinterpret_cast<Object4_2_0*>(data_ptr)-> C);

#define OBJECT_RETURN_MAT_4_2_0(A) \
	return reinterpret_cast<Object4_2_0*>(data_ptr)->runtime-> A .ptr();

#define OBJECT_BASE_RETURN_BODY(A, B, C) \
	OBJECT_BASE_RETURN_BODY_TO_3_4_0(A, B, C) \
	OBJECT_BASE_RETURN_BODY_POST_3_4_0(A, B, C) \
	OBJECT_BASE_RETURN_BODY_POST_4_2_0(A, B, C)

#define OBJECT_RETURN_REF(T, M) OBJECT_BASE_RETURN_BODY(T, &, M)
#define OBJECT_RETURN_AS(T, M) OBJECT_BASE_RETURN_BODY(T,, M)
#define OBJECT_RETURN(M) OBJECT_BASE_RETURN_BODY(,, M)

#define OBJECT_RETURN_MATS(M, N) \
	OBJECT_BASE_RETURN_BODY_TO_3_4_0(,, M) \
	OBJECT_BASE_RETURN_BODY_POST_3_4_0(,, N) \
	OBJECT_RETURN_MAT_4_2_0(N)

typedef float(*Mat)[4];

class Object : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<Object> id() const;
	AnimData adt() const;
	DrawDataList drawdata() const;
	short type() const;
	short partype() const;
	int par1() const;
	int par2() const;
	int par3() const;
	std::string parsubstr() const;
	Object parent() const;
	Object track() const;
	Object proxy() const;
	Object proxy_group() const;
	Object proxy_from() const;
	Ipo ipo() const;
	bAction action() const;
	bAction poselib() const;
	bPose pose() const;
	bGPdata gpd() const;
	bAnimVizSettings avs() const;
	bMotionPath mpath() const;
	ListBase<ModifierData> modifiers() const;
	ListBase<GpencilModifierData> greasepencil_modifiers() const;
	ListBase<bFaceMap> fmaps() const;
	ListBase<ShaderFxData> shader_fx() const;
	int& mode() const;
	int& restore_mode() const;
	MaterialSlotArray materials() const;
	MaterialSlot active_mat() const;
	float* loc() const;
	float* dloc() const;
	float* scale() const;
	float* dscale() const;
	float* rot() const;
	float* drot() const;
	float* quat() const;
	float* dquat() const;
	float* rotAxis() const;
	float* drotAxis() const;
	float& rotAngle() const;
	float& drotAngle() const;
	Mat parentinv() const;
	Mat constinv() const;
	short& flag() const;
	short& transflag() const;
	short& protectflag() const;
	short& trackflag() const;
	short& upflag() const;
	short& nlaflag() const;
	char& duplicator_visibility_flag() const;
	short& base_flag() const;
	unsigned short base_local_view_bits() const;
	unsigned short& col_group() const;
	unsigned short& col_mask() const;
	short& rotmode() const;
	char& boundtype() const;
	char& collision_boundtype() const;
	short& dtx() const;
	char& dt() const;
	char& empty_drawtype() const;
	float& empty_drawsize() const;
	float& instance_faces_scale() const;
	short& index() const;
	unsigned short& actdef() const;
	float* color() const;
	short& softflag() const;
	char& shapeflag() const;
	short& shapenr() const;
	// Add ListBase constraints and particlesystem once exact type is identified
	PartDeflect pd() const;
	SoftBody soft() const;
	Collection instance_collection() const;
	// Add ListBase pc_ids once exact type is identified
	RigidBodyOb rigidbody_object() const;
	RigidBodyCon rigidbody_constraint() const;
	float* ima_ofs() const;
	ImageUser iuser() const;
	char& empty_image_visibility_flag() const;
	char& empty_image_depth() const;
	char& empty_image_flag() const;
	PreviewImage preview() const;
	ObjectLineArt lineart() const;

	// Keep in mind the enum type of this object when retrieving it's data block (can be null)
	template <typename T>
	T data() const {
		OBJECT_RETURN_AS(T, data);
	}
private:
	void** mat() const;
	char* matbits() const;
	int totcol() const;
	int actcol() const;
};

class CameraBGImage : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	CameraBGImage next() const;
	CameraBGImage prev() const;
	// Add ima and iuser later
	MovieClip clip() const;
	MovieClipUser cuser() const;
	float* offset() const;
	float& scale() const;
	float& rotation() const;
	float& alpha() const;
	short& flag() const;
	short& source() const;
};

class Camera : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<Camera> id() const;
	AnimData adt() const;
	char& type() const;
	char& dtx() const;
	short& flag() const;
	float& passepartalpha() const;
	float& clip_start() const;
	float& clip_end() const;
	float& lens() const;
	float& ortho_scale() const;
	float& drawsize() const;
	float& sensor_x() const;
	float& sensor_y() const;
	float& shiftx() const;
	float& shifty() const;
	float& dof_distance() const;
	Ipo ipo() const;
	// gpu_dof and dof should be added later
	ListBase<CameraBGImage> bg_images() const;
	char& sensor_fit() const;
	// stereo and runtime should be added later
};

class RenderData : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	int& sfra() const;
	int& efra() const;
};

class Scene : public BlenderDataWrapper {
public:
	using BlenderDataWrapper::BlenderDataWrapper;
	ID<Scene> id() const;
	RenderData r() const;
};
