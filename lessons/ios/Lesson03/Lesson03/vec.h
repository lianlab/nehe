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

#ifndef __VEC_H_INCLUDED
#define __VEC_H_INCLUDED

#include <math.h>

//A 2 component vector
class vec2
{
public:
    float x,y;

    vec2(float a, float b);
    vec2();
};

//Forward declaration
class vec4;

//A 3 component vector
class vec3
{
public:
    float x,y,z;

    vec3();
    vec3(float a, float b, float c);
    //cut off the w-component
    vec3(const vec4& v);

    float Length() const;

    //Make the vector have unit length
    vec3 Normalize() const;

    //computes a vector which is orthogonal to both of the input vectors
    static vec3 Cross(const vec3& a, const vec3& b);

    //compute the dot product which is cos(alpha) * this.Length * a.Length
    //where alpha is the (smaller) angle between the vectors
    float Dot(const vec3& a) const;
    vec3 Subtract(const vec3& a) const;
    vec3 Add(const vec3& a) const;
};

const vec3 operator+(const vec3& lhs, const vec3& rhs);
const vec3 operator-(const vec3& lhs, const vec3& rhs);
const float operator*(const vec3& lhs, const vec3& rhs);

//A 4 component vector
class vec4
{
public:
    float x,y,z,w;

    vec4(float a, float b, float c, float d);
    vec4();
    vec4(const vec3& v, float w);

    float Length() const;

    //compute the dot product which is cos(alpha) * this.Length * a.Length
    //where alpha is the (smaller) angle between the vectors
    float Dot(const vec4& a) const;
    vec4 Subtract(const vec4& a) const;
    vec4 Add(const vec4& a) const;
};

const vec4 operator+(const vec4& lhs, const vec4& rhs);
const vec4 operator-(const vec4& lhs, const vec4& rhs);
const float operator*(const vec4& lhs, const vec4& rhs);

#endif
