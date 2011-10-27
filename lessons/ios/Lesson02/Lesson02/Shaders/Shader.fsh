//
//  Shader.fsh
//  Lesson02
//
//  Created by Carsten Haubold on 27/10/11.
//  Copyright (c) 2011 Daemgen.net. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
