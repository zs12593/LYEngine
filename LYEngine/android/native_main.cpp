#include "jni.h"
#include "../base/Game.h"
#include "../base/log/Log.h"

using namespace ly;

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    Game::getInstance()->run();
    return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYRenderer_nativeLoop(JNIEnv *env, jobject instance) {
    Game::getInstance()->mainLoop();
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeSizeChanged(JNIEnv *env, jobject instance, jint w, jint h,
                                                jint oldw, jint oldh) {
    Log::d("nativeSizeChanged  w: %d", w);
}

extern "C" JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeResume(JNIEnv *env, jobject instance) {
    Game::getInstance()->onForeground();
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativePause(JNIEnv *env, jobject instance) {
    Game::getInstance()->onBackground();
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeKeyDown(JNIEnv *env, jobject instance, jint keyCode) {
    Log::d("nativeKeyDown keyCode: %d", keyCode);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeKeyUp(JNIEnv *env, jobject instance, jint keyCode) {
    Log::d("nativeKeyUp keyCode: %d", keyCode);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchDown(JNIEnv *env, jobject instance,
                                              jint pointer, jfloat x, jfloat y) {
    Log::d("nativeTouchDown x: %f y: %f", x, y);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchMove(JNIEnv *env, jobject instance,
                                              jintArray ids, jfloatArray xs, jfloatArray ys) {
    jfloat *x = env->GetFloatArrayElements(xs, nullptr);
    jfloat *y = env->GetFloatArrayElements(ys, nullptr);
    Log::d("nativeTouchMove x: %f y: %f", x[0], y[0]);
    env->ReleaseFloatArrayElements(xs, x, 0);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchUp(JNIEnv *env, jobject instance,
                                            jint pointer, jfloat x, jfloat y) {
    Log::d("nativeTouchDown x: %f y: %f", x, y);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchCancel(JNIEnv *env, jobject instance,
                                                jintArray ids, jfloatArray xs, jfloatArray ys) {
    jfloat *x = env->GetFloatArrayElements(xs, nullptr);
    jfloat *y = env->GetFloatArrayElements(ys, nullptr);
    Log::d("nativeTouchMove x: %f y: %f", x[0], y[0]);
}

}
