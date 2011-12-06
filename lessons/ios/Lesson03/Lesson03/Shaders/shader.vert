/*
 Copyright (C) 2011 by Carsten Haubold
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

//the incoming vertex' position
attribute vec4 position;

//and its color
attribute vec3 color;

//our modelview matrix
uniform mat4 modelViewMatrix;

//the varying statement tells the shader pipeline that this variable
//has to be passed on to the next stage (so the fragment shader)
varying lowp vec3 colorVarying;


//the shader entry point is the main method
void main()
{    
    colorVarying = color; //save the color for the fragment shader
    gl_Position = modelViewMatrix * position; //the position is now multiplied by our rotation matrix
}
