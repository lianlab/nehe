package net.gamedev.nehe.android.lesson01;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView.Renderer;
import android.util.Log;

//import all GL functions so we don't have to type GLES20 before each function call
import static android.opengl.GLES20.*;

public class Lesson01Renderer implements Renderer {

	// needed for resource loading
	private Context context = null;

	// shader for all rendering
	private Shader shader = null;
	private int positionAttribLocation = 0;

	private int vertexVBO = 0;

	private int mFrameCount = 0;

	private long mStartTimeNS;

	private FloatBuffer vertices;

	public Lesson01Renderer(Context context) {
		this.context = context;
		shader = new Shader();
		mStartTimeNS = System.nanoTime();
	}

	public void onDrawFrame(GL10 arg0) {
		//measure performance
		++mFrameCount ;
		if (mFrameCount % 50 == 0) {
		      long now = System.nanoTime();
		      double msPerFrame = (now - mStartTimeNS) / 1e6 / mFrameCount;
		      Log.i("NeHe", "ms per frame: " + msPerFrame + 
		             " (fps: " + (1000/msPerFrame) + ")");
		      mFrameCount = 0;
		      mStartTimeNS = now;
		}
		
		//draw
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, null);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	// all setup and data loading goes here
	public void onSurfaceCreated(GL10 arg0, EGLConfig arg1) {
		// setup shader
		// TODO: read from file!
		String vShaderStr = "attribute vec4 position;    \n"
				+ "void main()                  \n"
				+ "{                            \n"
				+ "   gl_Position = position;  \n"
				+ "}                            \n";

		String fShaderStr = "precision mediump float;					  \n"
				+ "void main()                                  \n"
				+ "{                                            \n"
				+ "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
				+ "}                                            \n";

		shader.addVertexShader(vShaderStr);
		shader.addFragmentShader(fShaderStr);
		shader.linkProgram();
		glUseProgram(shader.getProgram());
		positionAttribLocation = glGetAttribLocation(shader.getProgram(),
				"position");

		// setup geometry
		float[] verticesData = { 0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f,
				-0.5f, 0.0f };
		vertices = ByteBuffer
				.allocateDirect(verticesData.length * 4)
				.order(ByteOrder.nativeOrder()).asFloatBuffer();
		vertices.put(verticesData).position(0);
	}

	// resizing or reorienting the screen has happened,
	// adjust projection matrices
	public void onSurfaceChanged(GL10 arg0, int arg1, int arg2) {

	}
}
