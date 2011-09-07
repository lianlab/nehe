package net.gamedev.nehe.android.lesson01;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;

public class Lesson01Activity extends Activity {
    private GLSurfaceView glSurfaceView = null;
	
	/** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        glSurfaceView = new GLSurfaceView(this);
        
        Log.d("NeHe", "Is GLES 2 supported? " + (new Boolean(detectOpenGLES20())).toString());
        
        //we definitely want a GLES 2 context
        glSurfaceView.setEGLContextClientVersion(2);
        //and create our own renderer
        glSurfaceView.setRenderer(new Lesson01Renderer(this));
        
        setContentView(glSurfaceView);
    }
    
    private boolean detectOpenGLES20() 
    {
        ActivityManager am =
            (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();
        return (info.reqGlEsVersion >= 0x20000);
    }
}