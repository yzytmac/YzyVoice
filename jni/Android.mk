LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := fmod-prebuilt
LOCAL_SRC_FILES := libfmod.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := fmodL-prebuilt
LOCAL_SRC_FILES := libfmodL.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := yzyvoice
LOCAL_SRC_FILES := YzyVoice.cpp
LOCAL_SHARED_LIBRARIES := fmod-prebuilt fmodL-prebuilt
LOCAL_LDLIBS := -llog
LOCAL_CPP_FEATURES := exceptions

include $(BUILD_SHARED_LIBRARY)
