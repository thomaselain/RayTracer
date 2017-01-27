/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:04:35 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 15:38:13 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#define A		f[0]
#define B		f[1]
#define C		f[2]
#define D		f[3]
#define RES_0	f[4]
#define RES_1	f[5]

/*
** Check if the ray intersects with the cylinder given as parameter
*/

float		find_cylinder_inter(t_ray *r, t_obj *o)
{
	float		f[6];

	A = vector_dot(r->direction, r->direction) - powf(vector_dot(o->direction,
		r->direction), 2);
	B = 2 * (vector_dot(r->direction, vecotr_sub(r->origin, o->origin)) -
		vector_dot(r->direction, o->direction) * vector_dot(vector_sub(
			r->origin, o->origin), o->direction));
	C = vector_dot(vector_sub(r->origin, o->origin), vector_sub(r->origin,
		o->origin)) - powf(vector_dot(vector_sub(r->origin, o->origin),
			o->direction), 2) - powf(o->radius, 2);
	D = powf(B, 2) - 4 * A * C;
	if (D < 0)
		return (MAX_SIZE);
	RES_0 = (-B - sqrtf(D)) / (A + A);
	RES_1 = (-B + sqrtf(D)) / (A + A);
	return ((RES_0 < RES_1) ? (RES_0) : (RES_1));
}
