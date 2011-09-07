package net.gamedev.nehe.android.lesson01;

//import all GL functions so we don't have to type GLES20 before each function call
import static android.opengl.GLES20.*;

import java.security.InvalidParameterException;

import android.util.Log;

public class Shader {
	
	private int vertexShader = 0;
	private int fragmentShader = 0;
	private int programObject = 0;
	
	public void addVertexShader(String source) throws InvalidParameterException
	{
		vertexShader = loadShader(GL_VERTEX_SHADER, source);
	}
	
	public void addFragmentShader(String source) throws InvalidParameterException
	{
		fragmentShader = loadShader(GL_FRAGMENT_SHADER, source);
	}
	
	public boolean linkProgram()
	{
        programObject = glCreateProgram();

        if (programObject == 0)
            return false;

        glAttachShader(programObject, vertexShader);
        glAttachShader(programObject, fragmentShader);

        //glBindAttribLocation(programObject, 0, "position");

        glLinkProgram(programObject);

        int[] linkStatus = new int[1];
        glGetProgramiv(programObject, GL_LINK_STATUS, linkStatus, 0);

        if (linkStatus[0] == 0)
        {
            Log.e("NeHe", "Linking program failed:"+glGetProgramInfoLog(programObject));
            glDeleteProgram(programObject);
            return false;
        }
        
        return true;
	}
	
	public int getProgram()
	{
		return programObject;
	}
	
    private int loadShader(int shaderType, String source)
    {
        int shader;
        int[] compiled = new int[1];

        // Create the shader object
        shader = glCreateShader(shaderType);

        if (shader == 0)
        	return 0;

        glShaderSource(shader, source);
        glCompileShader(shader);

        glGetShaderiv(shader, GL_COMPILE_STATUS, compiled, 0);

        if (compiled[0] == 0)
        {
            Log.e("NeHe", glGetShaderInfoLog(shader));
            glDeleteShader(shader);
            return 0;
        }
        return shader;
    }
}
