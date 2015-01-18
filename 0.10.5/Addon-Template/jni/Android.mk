LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := modName
LOCAL_SRC_FILES := main.cpp
LOCAL_LDLIBS := -L$(LOCAL_PATH) -llog -ldl -lminecraftpe -lmcpelauncher_tinysubstrate
include $(BUILD_SHARED_LIBRARY)
