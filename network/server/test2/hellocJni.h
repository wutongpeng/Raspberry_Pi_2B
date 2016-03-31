#include <jni.h>
#include "HelloJni.h"
#include <stdio.h>

JNIEXPORT void JNICALL 
Java_HelloJni_displayHelloJni(JNIEnv *env, jobject obj) 
{
    printf("Hello Dynamic Link Library has been calling!\n");
    printf("Java_HelloJni_displayHelloJni method has been executed!\n");
    return;
}