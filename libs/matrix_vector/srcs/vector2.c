/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:36:15 by svassal           #+#    #+#             */
/*   Updated: 2017/03/13 21:41:19 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#define COS cs_angle[0]
#define SIN cs_angle[1]

/*
** Gives the cross product of vector 1 and vector 2
*/

t_vector4f		vector_cross(t_vector4f v1, t_vector4f v2)
{
	float		f[4];
	t_vector4f	r_v;

	X = vector_get_y(&v1) * vector_get_z(&v2) -
		vector_get_z(&v1) * vector_get_y(&v2);
	Y = vector_get_z(&v1) * vector_get_x(&v2) -
		vector_get_x(&v1) * vector_get_z(&v2);
	Z = vector_get_x(&v1) * vector_get_y(&v2) -
		vector_get_y(&v1) * vector_get_x(&v2);
	W = 0;
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Return the normal of the given vector
*/

t_vector4f		vector_normalize(t_vector4f v)
{
	float		l;
	float		f[4];
	t_vector4f	r_v;

	l = vector_length(v);
	if (l != 0)
	{
		X = vector_get_x(&v) / l;
		Y = vector_get_y(&v) / l;
		Z = vector_get_z(&v) / l;
		W = vector_get_w(&v) / l;
		define_vector(&r_v, f);
	}
	else
		define_vector(&r_v, (float[4]){0, 0, 0, 0});
	return (r_v);
}

/*
** Rotate the vector v and return it as a fresh new copy
*/

t_vector4f		vector_rotate(t_vector4f v, t_vector4f axis, float angle)
{
	float		cs_angle[2];
	float		f[4];
	t_vector4f	r_v;

	cs_angle[0] = (float)cos(angle);
	cs_angle[1] = (float)sin(angle);
	X = v.x * (COS + powf(axis.x, 2) * (1 - COS));
	X += v.y * (axis.x * axis.y * (1 - COS) - axis.z * SIN);
	X += v.z * (axis.x * axis.z * (1 - COS)) + axis.y * SIN;
	Y = v.x * (axis.y * axis.x * (1 - COS) + axis.z * SIN);
	Y += v.y * (COS + powf(axis.y, 2) * (1 - COS));
	Y += v.z * (axis.y * axis.z * (1 - COS) - axis.x * SIN);
	Z = v.x * (axis.z * axis.x * (1 - COS) - axis.y * SIN);
	Z += v.y * (axis.z * axis.y * (1 - COS) + axis.x * SIN);
	Z += v.z * (COS + powf(axis.z, 2) * (1 - COS));
	W = 0;
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Linear interpolation
*/

t_vector4f		vector_lerp(t_vector4f v, t_vector4f dest, float lerp_fact)
{
	t_vector4f		t_v_1;
	t_vector4f		t_v_2;

	t_v_1 = vector_add_vec(v, dest);
	t_v_2 = vector_mul_flo(t_v_1, lerp_fact);
	t_v_1 = vector_add_vec(v, t_v_2);
	return (t_v_1);
}
