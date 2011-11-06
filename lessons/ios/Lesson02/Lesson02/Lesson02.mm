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

#include "Lesson02.h"

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#include <vector>

//lesson constructor
Lesson02::Lesson02()
: m_vertexBuffer(0),
  m_colorBuffer(0),
  m_shader(NULL)
{
    //initialize values
}

//lesson destructor
Lesson02::~Lesson02()
{
    //do cleanup
}

//initializing all OpenGL related things
void Lesson02::init()
{
    NSLog(@"Init..");
    
    //set the color we use for clearing our colorRenderbuffer to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    //---------------------------------------------------
    //create a triangle
    std::vector<float> geometryData;
    
    //4 floats define one vertex (x, y, z and w), first one is lower left
    geometryData.push_back(-0.5); geometryData.push_back(-0.5); geometryData.push_back(0.0); geometryData.push_back(1.0);
    //we go counter clockwise, so top vertex next
    geometryData.push_back( 0.0); geometryData.push_back( 0.5); geometryData.push_back(0.0); geometryData.push_back(1.0);
    //lower right vertex is last
    geometryData.push_back( 0.5); geometryData.push_back(-0.5); geometryData.push_back(0.0); geometryData.push_back(1.0);
    
    //generate an ID for our geometry buffer in the video memory and make it the active one
    glGenBuffers(1, &m_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    
    //send the data to the video memory
    glBufferData(GL_ARRAY_BUFFER, geometryData.size() * sizeof(float), &geometryData[0], GL_STATIC_DRAW);
    
    
    //create a color buffer, to make our triangle look pretty
    std::vector<float> colorData;
    
    //3 floats define one color value (red, green and blue) with 0 no intensity and 1 full intensity
    //each color triplet is assigned to the vertex at the same position in the buffer, so first color -> first vertex
    
    //first vertex is red
    colorData.push_back(1.0); colorData.push_back(0.0); colorData.push_back(0.0);
    //top vertex is green
    colorData.push_back(0.0); colorData.push_back(1.0); colorData.push_back(0.0);
    //lower right vertex is blue
    colorData.push_back(0.0); colorData.push_back(0.0); colorData.push_back(1.0);
    
    //generate an ID for the color buffer in the video memory and make it the active one
    glGenBuffers(1, &m_colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
    
    //send the data to the video memory
    glBufferData(GL_ARRAY_BUFFER, colorData.size() * sizeof(float), &colorData[0], GL_STATIC_DRAW);
    
    //---------------------------------------------------
    //load our shader
    m_shader = new Shader("shader.vert", "shader.frag");
    
    if(!m_shader->compileAndLink())
    {
        NSLog(@"Encountered problems when loading shader, application will crash...");
    }
    
    //tell OpenGL to use this shader for all coming rendering
    glUseProgram(m_shader->getProgram());
    
    //get the attachment points for the attributes position and color
    m_positionLocation = glGetAttribLocation(m_shader->getProgram(), "position");
    m_colorLocation = glGetAttribLocation(m_shader->getProgram(), "color");
    
    //enable these attributes
    glEnableVertexAttribArray(m_positionLocation);
    glEnableVertexAttribArray(m_colorLocation);
    
    NSLog(@"Init done...");
}

//drawing a frame
void Lesson02::draw()
{
    NSLog(@"Drawing");
    //clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    
    //bind the geometry VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    //point the position attribute to this buffer, being tuples of 4 floats for each vertex
    glVertexAttribPointer(m_positionLocation, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    
    //bint the color VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
    //this attribute is only 3 floats per vertex
    glVertexAttribPointer(m_colorLocation, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    //initiate the drawing process, we want a triangle, start at index 0 and draw 3 vertices
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    NSLog(@"Drawing done...");
}