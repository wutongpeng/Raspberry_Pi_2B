#include "HelloJNI.h"
int i = 0;
JNIEXPORT jint JNICALL Java_HelloJNI_get(JNIEnv *env, jclass jc)
{
    return i;
}
JNIEXPORT void JNICALL Java_HelloJNI_set(JNIEnv *env, jclass jc, jint j)
{
    i = j;
}
