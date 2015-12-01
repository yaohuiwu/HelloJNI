#include <jni.h>
#include <string.h>
#define LOG_TAG "HelloJNI"
#include <android/log.h>

#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)
/* Native interface, it will be call in java code */
JNIEXPORT jstring JNICALL Java_com_example_yaohui_testjni_HelloJNI_sayHello
        (JNIEnv *env, jclass jobject, jstring inputStr)
{
    LOGI("say Hello World From libHelloJNI.so!");
    // 从 instring 字符串取得指向字符串 UTF 编码的指针
    const char *str = (const char *) (*env)->GetStringUTFChars(env, inputStr, JNI_FALSE);
    LOGI("Your name is %s", (const char *)str);

    char helloStr[100];
    helloStr[0]='\0';
    strcat(helloStr, "hello ");
    strcat(helloStr, str);

    LOGI("hello str:%s", helloStr);

    // 通知虚拟机本地代码不再需要通过 str 访问 Java 字符串。
    (*env)->ReleaseStringUTFChars(env, inputStr, (const char *) str);
    return (*env)->NewStringUTF(env, helloStr);
}

/* This function will be call when the library first be load.
 * You can do some init in the libray. return which version jni it support.
 */
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    void *venv;
    LOGI("dufresne----->JNI_OnLoad!");
    if ((*vm)->GetEnv(vm, (void**) &venv, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("dufresne--->ERROR: GetEnv failed");
        return -1;
    }
    return JNI_VERSION_1_4;
}