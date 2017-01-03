#include "jni.h"
#include "base/Game.h"

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {

    ly::Game::getInstance()->run();

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_GameActivity_test(JNIEnv *env, jobject instance) {

}

JNIEXPORT jstring JNICALL
Java_com_ly_lyengine_GameActivity_getString(JNIEnv *env, jobject instance) {
    std::string retVal = ly::Game::getInstance()->getString();
    return env->NewStringUTF(retVal.c_str());
}

}
