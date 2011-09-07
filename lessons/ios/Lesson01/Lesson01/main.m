//
//  main.m
//  Lesson01
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 NeHe Productions. All rights reserved.
//

#import <UIKit/UIKit.h>

//standard main method, looks like that for every iOS app..
int main(int argc, char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSLog(@"Running app");
    int retVal = UIApplicationMain(argc, argv, nil, nil);
    [pool release];
    return retVal;
}
