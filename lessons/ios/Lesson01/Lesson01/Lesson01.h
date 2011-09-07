//
//  Lesson01.h
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#ifndef _LESSON01_H_
#define _LESSON01_H_

#include "Lesson.h"

//We derive our current lesson class from the general lesson class
class Lesson01 : public Lesson
{
public:
    //overwrite all important methods
    Lesson01();
    virtual ~Lesson01();
    
    virtual void init();
    virtual void draw();
};

#endif