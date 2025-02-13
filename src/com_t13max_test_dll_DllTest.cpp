#include "jni.h"
#include <iostream>
#include "com_t13max_test_dll_DllTest.h"
JNIEXPORT jint JNICALL Java_com_t13max_test_dll_DllTest_add
  (JNIEnv *evn, jobject obj, jint a, jint b){
	return a+b;
}
