//
//  EAGLView.h
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

//forward declarations again
@class EAGLContext;
class Lesson;

// This class combines our OpenGL context (which is our access to all drawing functionality)
// with a UIView that can be displayed on the iOS device. It handles the creation and presentation
// of our drawing surface, as well as handling the render loop which allows for seamless animations.
@interface EAGLView : UIView {
@private
    // The pixel dimensions of the CAEAGLLayer.
    GLint framebufferWidth;
    GLint framebufferHeight;
    
    // These are the buffers we render to: the colorRenderbuffer will contain the color that we will
    // finaly see on the screen, the depth renderbuffer has to be used if we want to make sure, that
    // we always see only the closest object and not just the one that has been drawn most recently.
    // The framebuffer is a collection of buffers to use together while rendering, here it is either
    // just the color buffer, or color and depth renderbuffer.
    GLuint defaultFramebuffer, colorRenderbuffer, depthRenderbuffer;
    
    // The display link is used to create a render loop
    CADisplayLink* displayLink;
    
    // Do we need a depth buffer
    BOOL useDepthBuffer;
    
    // The pointer to the lesson which we're rendering
    Lesson* lesson;
    
    // Did we already initialize our lesson?
    BOOL lessonIsInitialized;
}

// The OpenGL context as a property (has autogenerated getter and setter)
@property (nonatomic, retain) EAGLContext *context;

// Configuration setters
- (void) setDepthBufferNeeded:(BOOL)needed;
- (void) setLesson:(Lesson*)newLesson;

//if we want OpenGL to repaint with the screens refresh rate, we use this render loop
- (void) startRenderLoop;
- (void) stopRenderLoop;
@end
