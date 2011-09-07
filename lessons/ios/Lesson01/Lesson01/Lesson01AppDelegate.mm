//
//  Lesson01AppDelegate.m
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#import "Lesson01AppDelegate.h"

#import "EAGLView.h"
#include "Lesson01.h"

//now we implement all methods needed by our delegate
@implementation Lesson01AppDelegate

//
@synthesize window;
@synthesize glView;

//this method tells us, that our application has started and we can set up our OpenGL things,
//as the window is set up, and thus our glView is going to be displayed soon
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    //for the first lesson we don't need a depth buffer as we're not drawing any geometry yet
    [glView setDepthBufferNeeded:FALSE];
    
    //we create our lesson which contains the OpenGL code
    //(allocated with new -> has to be cleaned up with delete!)
    lesson = new Lesson01();
    
    //we tell our OpenGL view which lesson we want to use for rendering.
    [glView setLesson:lesson];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    //the app is going to be suspended to the background,
    //so we should stop our render loop
    [glView stopRenderLoop];
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    //we could do something here when the application entered the background
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    //we could start preparing stuff for becoming active again
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    //we're on stage! so let's draw some nice stuff
    [glView startRenderLoop];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    //before shutdown we stop the render loop
    [glView stopRenderLoop];
}

//dealloc is the destructor in Objective-C, so clean up all allocated things
- (void)dealloc
{
    [window release];
    [glView release];
    delete lesson;
    [super dealloc];
}

@end
