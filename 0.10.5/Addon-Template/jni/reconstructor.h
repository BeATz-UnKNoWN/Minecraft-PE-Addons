#include <jni.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <android/log.h>

#define MOD "Addon"

void reconstructVTable(void** vtable) {
	int i = -1;
	while(true) {
		i++;
		void* method = vtable[i];
		if(method == NULL) {
			if(i >= 3) {
				break;
			}
			__android_log_print(ANDROID_LOG_INFO, MOD, "vtable: %i %i null\n", i, method);
			continue;
		}
		
		Dl_info info;
		int ret = dladdr(method, &info);
		if(ret != 0) {
			void* addrcheck = dlsym(RTLD_DEFAULT, info.dli_sname);
			__android_log_print(ANDROID_LOG_INFO, MOD, "vtable %i %i %s %i\n", i, method, info.dli_sname, addrcheck);
		}else{
			__android_log_print(ANDROID_LOG_INFO, MOD, "vtable: %i %i not found\n", i, method);
		}
	}
}
