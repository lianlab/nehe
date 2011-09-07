//
//  Lesson01AppDelegate.h
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#import <UIKit/UIKit.h>

//we want to create variables of these classes, but don't need their implementation yet,
//so we just tell the compiler that they exist - called forward declaration
@class EAGLView;
class Lesson;

//This is our delegate class. It handles all messages from the device's operating system
@interface Lesson01AppDelegate : NSObject <UIApplicationDelegate> {
    //our main window, covering the whole screen
    UIWindow *window;
    
    //in this window we will embed a view which acts as OpenGL context
    EAGLView *glView;
    
    //we store a pointer to our lesson so we can delete it at program shutdown
    Lesson *lesson;
}

//we configure these variables in the interface builder (IB), thus they have to be declared as IBOutlet
//properties get accessor methods by synthesizing them in the source file (.mm)
@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet EAGLView *glView;

@end
