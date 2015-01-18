#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <substrate.h>
#include <reconstructor.h>

#define TAG "modName"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* mcpelibhandle = dlopen("libminecraftpe.so", RTLD_LAZY);
	
	dlerror();
	
	
	
	const char* error = dlerror();
	if (error) {
		__android_log_print(ANDROID_LOG_INFO, TAG, "dlerror: %s", error);
	}
	
	return JNI_VERSION_1_2;
}
