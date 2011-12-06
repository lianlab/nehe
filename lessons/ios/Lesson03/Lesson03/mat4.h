/*
Taken from Kazmath and converted to be stand-alone for the NeHe Lessons by Carsten Haubold

Copyright (c) 2008, Luke Benstead, Carsten Haubold
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MAT4_H_INCLUDED
#define MAT4_H_INCLUDED

#include <math.h>

#include "vec.h"

/*
A 4x4 matrix

        | 0   4   8  12 |
  mat = | 1   5   9  13 |
        | 2   6  10  14 |
        | 3   7  11  15 |
*/
class mat4
{
    public:
        float mat[16];

        mat4();
        mat4(float matrix[16]);

        //Basic transformations
        static mat4 CreateIdentity();
        static mat4 CreateRotationAxis(float degrees, float axis_x, float axis_y, float axis_z);
        static mat4 CreateRotationPitchYawRoll(float pitch, float yaw, float roll);
        static mat4 CreateScale(float x, float y, float z);
        static mat4 CreateTranslation(float x, float y, float z);

        //Projection matrices
        static mat4 CreatePerspectiveProjection(float fovY, float aspect, float zNear, float zFar);
        static mat4 CreateOrthographicProjection(float left, float right, float bottom, float top, float nearVal, float farVal);
        //Camera Setup
        static mat4 CreateLookAt(const vec3& pEye, const vec3& pCenter, const vec3& pUp);

        mat4 Inverse() const;
        bool IsIdentity() const;
        mat4 Transpose() const;
        mat4 Multiply(const mat4& other) const; //returns this * other
        bool Equal(const mat4& other, float threshold = 0.0) const;

        vec3 GetUpVec3() const;
        vec3 GetRightVec3() const;
        vec3 GetForwardVec3() const;

        //Transform a vector through this matrix:
        vec3 Multiply(const vec3& v) const; //returns vec3( this * vec4(v,1.0) )
        vec4 Multiply(const vec4& v) const; //returns this * v
};

const mat4 operator*(const mat4& lhs, const mat4& rhs);
const vec3 operator*(const mat4& lhs, const vec3& rhs);
const vec4 operator*(const mat4& lhs, const vec4& rhs);

#endif /* MAT4_H_INCLUDED */
