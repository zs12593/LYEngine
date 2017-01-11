package com.ly.lyengine;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.view.MotionEvent;

public class LYGLView extends GLSurfaceView {

    public LYGLView(Context context) {
        super(context);
        init();
    }

    public LYGLView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init() {
        this.setEGLContextClientVersion(2);
        this.setFocusableInTouchMode(true);
    }

    @Override
    public void onResume() {
        super.onResume();
        this.setRenderMode(RENDERMODE_CONTINUOUSLY);
        nativeResume();
    }

    @Override
    public void onPause() {
        super.onPause();
        nativePause();
        this.setRenderMode(RENDERMODE_WHEN_DIRTY);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int pointerNumber = event.getPointerCount();
        int[] ids = new int[pointerNumber];
        float[] xs = new float[pointerNumber];
        float[] ys = new float[pointerNumber];
        int pointer;
        float x, y;

        switch (event.getAction() & MotionEvent.ACTION_MASK) {
            case MotionEvent.ACTION_POINTER_DOWN:
                int pd = event.getAction() >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                pointer = event.getPointerId(pd);
                x = event.getX(pd);
                y = event.getY(pd);
                nativeTouchDown(pointer, x, y);
                break;
            case MotionEvent.ACTION_DOWN:
                nativeTouchDown(event.getPointerId(0), xs[0], ys[0]);
                break;
            case MotionEvent.ACTION_MOVE:
                nativeTouchMove(ids, xs, ys);
                break;
            case MotionEvent.ACTION_POINTER_UP:
                int pu = event.getAction() >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                pointer = event.getPointerId(pu);
                x = event.getX(pu);
                y = event.getY(pu);
                nativeTouchUp(pointer, x, y);
                break;
            case MotionEvent.ACTION_UP:
                nativeTouchUp(event.getPointerId(0), xs[0], ys[0]);
                break;
            case MotionEvent.ACTION_CANCEL:
                nativeTouchCancel(ids, xs, ys);
                break;
        }
        return true;
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        nativeSizeChanged(w, h, oldw, oldh);
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        nativeKeyDown(keyCode);
        return true;
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        nativeKeyUp(keyCode);
        return true;
    }

    private native void nativeSizeChanged(int w, int h, int oldw, int oldh);

    private native void nativePause();

    private native void nativeResume();

    private native void nativeKeyDown(int keyCode);

    private native void nativeKeyUp(int keyCode);

    private native void nativeTouchDown(int pointer, float x, float y);

    private native void nativeTouchMove(int pointer[], float xs[], float ys[]);

    private native void nativeTouchUp(int pointer, float x, float y);

    private native void nativeTouchCancel(int pointer[], float xs[], float ys[]);

}
