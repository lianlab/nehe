//
//  Shader.fsh
//  Lesson01
//
//  Created by Carsten Haubold on 7/08/11.
//  Copyright 2011 Daemgen.net. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
