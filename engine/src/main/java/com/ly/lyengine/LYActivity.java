package com.ly.lyengine;

import android.app.Activity;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.text.TextUtils;
import android.widget.RelativeLayout;

public class LYActivity extends Activity {
    private static final String LIB_NAME_META = "ly.engine.lib";
    protected LYGLView mGLView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        loadNativeLib();

        initView();
    }

    private void loadNativeLib() {
        String libName = null;
        try {
            ApplicationInfo appInfo = getPackageManager().getApplicationInfo(getPackageName(),
                    PackageManager.GET_META_DATA);
            libName = appInfo.metaData.getString(LIB_NAME_META);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (TextUtils.isEmpty(libName))
            libName = "LYGame";
        System.loadLibrary(libName);
    }

    protected void initView() {
        RelativeLayout contentView = new RelativeLayout(this);
        setContentView(contentView);

        mGLView = new LYGLView(this);
        contentView.addView(mGLView);
        setEGLConfigChooser(8, 8, 8, 8, 24, 8);
        mGLView.setRenderer(new LYRenderer());
    }

    protected void setEGLConfigChooser(int redSize, int greenSize, int blueSize,
                                       int alphaSize, int depthSize, int stencilSize) {
        mGLView.setEGLConfigChooser(redSize, greenSize, blueSize, alphaSize, depthSize, stencilSize);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
    }
}
