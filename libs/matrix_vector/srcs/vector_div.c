/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:57:42 by svassal           #+#    #+#             */
/*   Updated: 2017/01/25 22:36:51 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Divide first vector by the second one
*/

t_vector4f		vector_div_vec(t_vector4f v1, t_vector4f v2)
{
	float		f[4];
	t_vector4f	r_v;

	X = vector_get_x(&v1) / vector_get_x(&v2);
	Y = vector_get_y(&v1) / vector_get_y(&v2);
	Z = vector_get_z(&v1) / vector_get_z(&v2);
	W = vector_get_w(&v1) / vector_get_w(&v2);
	define_vector(&r_v, f);
	return (r_v);
}

/*
** Divide vector's datas by a float value
*/

t_vector4f		vector_div_flo(t_vector4f v, float r)
{
	float		f[4];
	t_vector4f	r_v;

	X = vector_get_x(&v) / r;
	Y = vector_get_y(&v) / r;
	Z = vector_get_z(&v) / r;
	W = vector_get_w(&v) / r;
	define_vector(&r_v, f);
	return (r_v);
}
