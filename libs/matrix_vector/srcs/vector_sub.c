/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:11:09 by svassal           #+#    #+#             */
/*   Updated: 2017/01/13 13:42:08 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Substract first vector by the second one
*/

t_vector4f		vector_sub_vec(t_vector4f v1, t_vector4f v2)
{
	float		f[4];
	t_vector4f	r_v;

	X = vector_get_x(&v1) - vector_get_x(&v2);
	Y = vector_get_y(&v1) - vector_get_y(&v2);
	Z = vector_get_z(&v1) - vector_get_z(&v2);
	W = vector_get_w(&v1) - vector_get_w(&v2);
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Substract vector's datas by a float value
*/

t_vector4f		vector_sub_flo(t_vector4f v, float r)
{
	float		f[4];
	t_vector4f	r_v;

	X = vector_get_x(&v) - r;
	Y = vector_get_y(&v) - r;
	Z = vector_get_z(&v) - r;
	W = vector_get_w(&v) - r;
	define_vector(&r_v, f);
	return (r_v);
}
