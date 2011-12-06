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

#include "vec.h"

vec2::vec2(float a, float b)
{
    x=a;
    y=b;
}
vec2::vec2()
{
    x=y=0.0;
}
vec3::vec3()
{
    x=y=z=0.0;
}

vec3::vec3(float a, float b, float c)
{
    x=a;
    y=b;
    z=c;
}

vec3::vec3(const vec4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

float vec3::Length() const
{
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::Normalize() const
{
    vec3 result = *this;
    float l = Length();
    result.x /= l;
    result.y /= l;
    result.z /= l;
    return result;
}

vec3 vec3::Cross(const vec3& a, const vec3& b)
{
    vec3 v;

    v.x = (a.y * b.z) - (a.z * b.y);
    v.y = (a.z * b.x) - (a.x * b.z);
    v.z = (a.x * b.y) - (a.y * b.x);

    return v;
}

float vec3::Dot(const vec3& a) const
{
    return x*a.x + y*a.y + z*a.z;
}


vec3 vec3::Subtract(const vec3& a) const
{
    vec3 result = *this;
    result.x -= a.x;
    result.y -= a.y;
    result.z -= a.z;
    return result;
}

vec3 vec3::Add(const vec3& a) const
{
    vec3 result = *this;
    result.x += a.x;
    result.y += a.y;
    result.z += a.z;
    return result;
}

const vec3 operator+(const vec3& lhs, const vec3& rhs)
{
	return lhs.Add(rhs);
}

const vec3 operator-(const vec3& lhs, const vec3& rhs)
{
	return lhs.Subtract(rhs);
}

const float operator*(const vec3& lhs, const vec3& rhs)
{
	return lhs.Dot(rhs);
}

vec4::vec4(float a, float b, float c, float d)
{
    x=a;
    y=b;
    z=c;
    w=d;
}

vec4::vec4()
{
    x=y=z=w=0.0;
}

vec4::vec4(const vec3& v, float w)
{
    x = v.x;
    y = v.y;
    z = v.z;
    this->w = w;
}

float vec4::Length() const
{
    return sqrt(x*x + y*y + z*z + w*w);
}

float vec4::Dot(const vec4& a) const
{
    return x*a.x + y*a.y + z*a.z + w*a.w;
}


vec4 vec4::Subtract(const vec4& a) const
{
    vec4 result = *this;
    result.x -= a.x;
    result.y -= a.y;
    result.z -= a.z;
    result.w -= a.w;
    return result;
}

vec4 vec4::Add(const vec4& a) const
{
    vec4 result = *this;
    result.x += a.x;
    result.y += a.y;
    result.z += a.z;
    result.w += a.w;
    return result;
}

const vec4 operator+(const vec4& lhs, const vec4& rhs)
{
	return lhs.Add(rhs);
}

const vec4 operator-(const vec4& lhs, const vec4& rhs)
{
	return lhs.Subtract(rhs);
}

const float operator*(const vec4& lhs, const vec4& rhs)
{
	return lhs.Dot(rhs);
}
