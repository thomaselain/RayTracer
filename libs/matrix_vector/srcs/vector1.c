/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:38:38 by svassal           #+#    #+#             */
/*   Updated: 2017/02/05 16:48:32 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Check if two vectors are equal (1) or not (0)
*/

char		vector_equals(t_vector4f v1, t_vector4f v2)
{
	if (vector_get_x(&v1) != vector_get_x(&v2))
		return (0);
	if (vector_get_y(&v1) != vector_get_y(&v2))
		return (0);
	if (vector_get_z(&v1) != vector_get_z(&v2))
		return (0);
	if (vector_get_w(&v1) != vector_get_w(&v2))
		return (0);
	return (1);
}

/*
** Gives the absolute of a vector
*/

t_vector4f	vector_abs(t_vector4f v)
{
	float		f[4];
	t_vector4f	r_v;

	X = (vector_get_x(&v) < 0) ? -(vector_get_x(&v)) : (vector_get_x(&v));
	Y = (vector_get_y(&v) < 0) ? -(vector_get_y(&v)) : (vector_get_y(&v));
	Z = (vector_get_z(&v) < 0) ? -(vector_get_z(&v)) : (vector_get_z(&v));
	W = (vector_get_w(&v) < 0) ? -(vector_get_w(&v)) : (vector_get_w(&v));
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Return the higher value between each of the vector's data
*/

float		vector_max(t_vector4f v)
{
	float		m;

	m = vector_get_x(&v);
	m = (m < vector_get_y(&v)) ? (vector_get_y(&v)) : (m);
	m = (m < vector_get_z(&v)) ? (vector_get_z(&v)) : (m);
	m = (m < vector_get_w(&v)) ? (vector_get_w(&v)) : (m);
	return (m);
}

/*
** Return vector's length
*/

float		vector_length(t_vector4f v)
{
	float		f[4];
	float		r;

	X = vector_get_x(&v) * vector_get_x(&v);
	Y = vector_get_y(&v) * vector_get_y(&v);
	Z = vector_get_z(&v) * vector_get_z(&v);
	W = vector_get_w(&v) * vector_get_w(&v);
	r = sqrtf(X + Y + Z + W);
	return (r);
}

/*
** Gives the dot product of two vectors v1 and v2
*/

float		vector_dot(t_vector4f v1, t_vector4f v2)
{
	float		f[4];

	X = vector_get_x(&v1) * vector_get_x(&v2);
	Y = vector_get_y(&v1) * vector_get_y(&v2);
	Z = vector_get_z(&v1) * vector_get_z(&v2);
	W = vector_get_w(&v1) * vector_get_w(&v2);
	return (X + Y + Z + W);
}
