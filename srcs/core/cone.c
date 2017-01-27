/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:32:35 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 16:43:34 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#define A			f[0]
#define B			f[1]
#define C			f[2]
#define D			f[3]
#define RES_0		f[4]
#define RES_1		f[5]

/*
** Check if the ray intersects with the cone given as parameter
*/

float		find_cone_inter(t_ray *r, t_object *o)
{
	float		f[6];

	A = vector_dot(r->direction, r->direction) - powf(vector_dot(r->direction,
		o->direction), 2) * (1 + powf(tanf(o->angle / 2), 2));
	B = 2 * ((vector_dot(r->direction, vector_sub_vec(r->origin, o->origin))) -
		(1 + powf(tanf(o->angle / 2), 2)) * vector_dot(r->direction,
			o->direction) * vector_dot(vector_sub_vec(r->origin, o->origin),
				o->direction));
	C = vector_dot(vector_sub_vec(r->origin, o->origin), vector_sub_vec(
		r->origin, o->origin)) - (1 + powf(tanf(o->angle / 2), 2)) *
			powf(vector_dot(vector_sub_vec(r->origin, o->origin),
				o->direction), 2);
	D = powf(B, 2) - 4 * A * C;
	if (D < 0.0)
		return (MAX_SIZE);
	RES_0 = (-B - sqrtf(D)) / (A + A);
	RES_1 = (-B + sqrtf(D)) / (A + A);
	return ((RES_0 < RES_1) ? (RES_0) : (RES_1));
}
