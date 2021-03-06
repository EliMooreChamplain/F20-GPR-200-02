/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	gproVector.h
	Interface for vectors. Sets an example for C and C++ compatible headers.

	Modified by: ____________
	Modified because: ____________
*/

#ifdef _GPRO_VECTOR_H_
#ifndef _GPRO_VECTOR_INL_
#define _GPRO_VECTOR_INL_


#ifdef __cplusplus

inline vec3::vec3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}
inline vec3::vec3(double const xc, double const yc, double const zc)
	: x(xc), y(yc), z(zc)
{
}
inline vec3::vec3(double3 const vc)
	: x(vc[0]), y(vc[1]), z(vc[2])
{
}
inline vec3::vec3(vec3 const& rh)
	: x(rh.x), y(rh.y), z(rh.z)
{
}

inline vec3& vec3::operator =(vec3 const& rh)
{
	x = rh.x;
	y = rh.y;
	z = rh.z;
	return *this;
}

inline vec3& vec3::operator +=(vec3 const& rh)
{
	x += rh.x;
	y += rh.y;
	z += rh.z;
	return *this;
}

inline vec3 const vec3::operator +(vec3 const& rh) const
{
	return vec3((x + rh.x), (y + rh.y), (z + rh.z));
}

inline vec3 operator-(const vec3& u, const vec3& v) {//ADDED
	return vec3(u.v[0] - v.v[0], u.v[1] - v.v[1], u.v[2] - v.v[2]);
}

inline vec3 operator*(double t, const vec3& v) {//ADDED
	return vec3(t * v.v[0], t * v.v[1], t * v.v[2]);
}

inline vec3 operator*(const vec3& v, double t) {//ADDED
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {//ADDED
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {//ADDED
	return u.v[0] * v.v[0]
		+ u.v[1] * v.v[1]
		+ u.v[2] * v.v[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {//ADDED
	return vec3(u.v[1] * v.v[2] - u.v[2] * v.v[1],
		u.v[2] * v.v[0] - u.v[0] * v.v[2],
		u.v[0] * v.v[1] - u.v[1] * v.v[0]);
}

inline vec3 unit_vector(vec3 v) {//ADDED
	return v/sqrt(pow(v.x,2) + pow(v.y,2) + pow(v.z,2));
}

#endif	// __cplusplus


inline doublev vec3default(double3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0.0f;
	return v_out;
}
inline doublev vec3init(double3 v_out, double const xc, double const yc, double const zc)
{
	v_out[0] = xc;
	v_out[1] = yc;
	v_out[2] = zc;
	return v_out;
}
inline doublev vec3copy(double3 v_out, double3 const v_rh)
{
	v_out[0] = v_rh[0];
	v_out[1] = v_rh[1];
	v_out[2] = v_rh[2];
	return v_out;
}

inline doublev vec3add(double3 v_lh_sum, double3 const v_rh)
{
	v_lh_sum[0] += v_rh[0];
	v_lh_sum[1] += v_rh[1];
	v_lh_sum[2] += v_rh[2];
	return v_lh_sum;
}

inline doublev vec3sum(double3 v_sum, double3 const v_lh, double3 const v_rh)
{
	return vec3init(v_sum, (v_lh[0] + v_rh[0]), (v_lh[1] + v_rh[1]), (v_lh[2] + v_rh[2]));
}


#endif	// !_GPRO_VECTOR_INL_
#endif	// _GPRO_VECTOR_H_