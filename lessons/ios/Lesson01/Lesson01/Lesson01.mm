//
//  Lesson01.cpp
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#include "Lesson01.h"

//lesson constructor
Lesson01::Lesson01()
{
    //initialize values
}

//lesson destructor
Lesson01::~Lesson01()
{
    //do cleanup
}

//initializing all OpenGL related things
void Lesson01::init()
{
    NSLog(@"Init..");
    
    //set the color we use for clearing our colorRenderbuffer to red
    glClearColor(1.0, 0.0, 0.0, 0.0);
}

//drawing a frame
void Lesson01::draw()
{
    //clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    
    //everything should be red now! yay :)
}