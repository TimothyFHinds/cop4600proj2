#include <jni.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include "read_file.cpp"
using namespace std;


extern "C"
JNIEXPORT jstring JNICALL Java_edu_ufl_cise_os_p2_P2Activity_stringFromJNI(JNIEnv *env, jobject obj, jstring inString)
{
    //convert JNI string into c-string (char*)
    const char *input = env->GetStringUTFChars(inString, NULL);
    if(NULL == input) return NULL;

    //call the readfile method
    const char * output = read_file(input);

    string ret_string(output);

    //return the String containing the file contents
    //return env->NewStringUTF(output);
    return env->NewStringUTF(ret_string.c_str());

    /* std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str()); */
}
