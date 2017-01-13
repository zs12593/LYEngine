#include "jni.h"
#include "../base/Game.h"
#include "../base/log/Log.h"
#include "../base/event/EventDispatcher.h"

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
    EventDispatcher::getInstance()->dispatch(new KeyEvent(InputEvent::KeyDown, keyCode));
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeKeyUp(JNIEnv *env, jobject instance, jint keyCode) {
    EventDispatcher::getInstance()->dispatch(new KeyEvent(InputEvent::KeyUp, keyCode));
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchDown(JNIEnv *env, jobject instance,
                                              jint pointer, jfloat x, jfloat y) {
    EventDispatcher::getInstance()->dispatch(
            new TouchEvent(InputEvent::TouchDown, new int[]{pointer}, new float[]{x},
                           new float[]{y}));
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchMove(JNIEnv *env, jobject instance,
                                              jintArray ids, jfloatArray xs, jfloatArray ys) {
    jboolean isCopy;
    jint *id = env->GetIntArrayElements(ids, &isCopy);
    if (!isCopy) {
        Log::e("native float array copy error");
        return;
    }
    jsize size = env->GetArrayLength(ids);
    int *tids = new int[size];
    for (int i = 0; i < size; i++)
        tids[i] = id[i];

    jfloat *x = env->GetFloatArrayElements(xs, &isCopy);
    if (!isCopy) {
        Log::e("native float array copy error");
        return;
    }
    size = env->GetArrayLength(xs);
    float *txs = new float[size];
    for (int i = 0; i < size; i++)
        txs[i] = x[i];

    jfloat *y = env->GetFloatArrayElements(ys, &isCopy);
    if (!isCopy) {
        Log::e("native float array copy error");
        return;
    }
    size = env->GetArrayLength(ys);
    float *tys = new float[size];
    for (int i = 0; i < size; i++)
        tys[i] = y[i];

    EventDispatcher::getInstance()->dispatch(new TouchEvent(InputEvent::TouchMove, tids, txs, tys));
    env->ReleaseIntArrayElements(ids, id, JNI_ABORT);
    env->ReleaseFloatArrayElements(xs, x, JNI_ABORT);
    env->ReleaseFloatArrayElements(ys, y, JNI_ABORT);
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchUp(JNIEnv *env, jobject instance,
                                            jint pointer, jfloat x, jfloat y) {
    EventDispatcher::getInstance()->dispatch(
            new TouchEvent(InputEvent::TouchUp, new int[]{pointer}, new float[]{x},
                           new float[]{y}));
}

JNIEXPORT void JNICALL
Java_com_ly_lyengine_LYGLView_nativeTouchCancel(JNIEnv *env, jobject instance,
                                                jintArray ids, jfloatArray xs, jfloatArray ys) {
    jboolean isCopy;
    jint *id = env->GetIntArrayElements(ids, &isCopy);
    if (!isCopy) {
        Log::e("native float array copy error");
        return;
    }
    jsize size = env->GetArrayLength(ids);
    int *tids = new int[size];
    for (int i = 0; i < size; i++)
        tids[i] = id[i];

    EventDispatcher::getInstance()->dispatch(new TouchEvent(InputEvent::TouchCancel, tids, nullptr,
                                                            nullptr));
    env->ReleaseIntArrayElements(ids, id, JNI_ABORT);
}

}
