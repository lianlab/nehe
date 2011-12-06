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

#ifndef _Lesson03_H_
#define _Lesson03_H_

#include "Lesson.h"
#include "Shader.h"
#include "mat4.h"

//We derive our current lesson class from the general lesson class
class Lesson03 : public Lesson
{
public:
    //overwrite all important methods
    Lesson03();
    virtual ~Lesson03();
    
    virtual void init();
    virtual void draw();
    
private:
    //our vertex buffer containing the geometry data for our triangle
    unsigned int m_geometryBuffer;
    
    //buffer ID for the color data in the video memory
    unsigned int m_colorBuffer;
    
    //the shader program we use for rendering
    Shader *m_shader;
    
    //locations for the vertex and color attribute in the shader
    int m_positionLocation, m_colorLocation;
    
    //the matrix for the current transformation of our triangle
    mat4 m_modelViewMatrix;
};

#endif