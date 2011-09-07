//
//  Lesson.cpp
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#include "Lesson.h"

//Lesson constructor, set default values
Lesson::Lesson():
    m_renderbufferWidth(0),
    m_renderbufferHeight(0)
{
    
}

//Lesson destructor
Lesson::~Lesson()
{
    //cleanup here
}

//save the renderbuffer size in the member variables
void Lesson::setRenderbufferSize(unsigned int width, unsigned int height)
{
    m_renderbufferWidth = width;
    m_renderbufferHeight = height;
}