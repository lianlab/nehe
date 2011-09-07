//
//  Lesson.h
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#ifndef _LESSON_H_
#define _LESSON_H_

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

//this is our general lesson class, providing the two most important methods init and draw
//which will be invoked by our EAGLView
class Lesson
{
public:
    //constructor
    Lesson();
    //the destructor has always to virtual!
    virtual ~Lesson();
    
    //abstract methods init and draw have to be defined in derived classes
    virtual void init() = 0;
    virtual void draw() = 0;
    
    //we need to know the size of our drawing canvas (called renderbuffer here),
    //so this method just saves the parameters in the member variables
    virtual void setRenderbufferSize(unsigned int width, unsigned int height);
    
//all protected stuff will be visible within derived classes, but from nowhere else    
protected:
    //fields for the renderbuffer size
    unsigned int m_renderbufferWidth, m_renderbufferHeight;
};

#endif