LOCAL_PATH := $(call my-dir)

#别人没有给我们源码，只给了so库，所以要预构建别人的so库，然后在构建自己的so库
#使用预构建库fmod.so
include $(CLEAR_VARS)
LOCAL_MODULE := fmod-prebuilt
LOCAL_SRC_FILES := libfmod.so
include $(PREBUILT_SHARED_LIBRARY)

#使用预构建库fmodL.so
include $(CLEAR_VARS)
LOCAL_MODULE := fmodL-prebuilt
LOCAL_SRC_FILES := libfmodL.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

#构建自己的so库，并将预构建库构建的新库一并打包进来
LOCAL_MODULE    := yzyvoice
LOCAL_SRC_FILES := YzyVoice.cpp
LOCAL_SHARED_LIBRARIES := fmod-prebuilt fmodL-prebuilt
LOCAL_LDLIBS := -llog
LOCAL_CPP_FEATURES := exceptions

include $(BUILD_SHARED_LIBRARY)
