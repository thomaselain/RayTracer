/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:04:35 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 17:59:04 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <vector.h>
#include <ray.h>
#define A		f[0]
#define B		f[1]
#define C		f[2]
#define D		f[3]
#define RES_1	f[4]
#define RES_2	f[5]
#define PROJ	f[6]

/*
 ** Check if the ray intersects with the cylinder given as parameter
 */

float		find_cylinder_inter(t_ray *r, t_object *o)
{
	float		f[7];

	A = vector_dot(r->dir, r->dir) - powf(vector_dot(o->direction,
				r->dir), 2);
	B = 2 * (vector_dot(r->dir, vector_sub_vec(r->pos, o->origin)) -
			vector_dot(r->dir, o->direction) * vector_dot(vector_sub_vec(
					r->pos, o->origin), o->direction));
	C = vector_dot(vector_sub_vec(r->pos, o->origin), vector_sub_vec(r->pos,
				o->origin)) - powf(vector_dot(vector_sub_vec(r->pos, o->origin),
					o->direction), 2) - powf(o->radius, 2);
	D = powf(B, 2) - 4 * A * C;
	if (D < 0)
		return (MAX_SIZE);
	RES_1 = (-B - sqrtf(D)) / (A + A);
	RES_2 = (-B + sqrtf(D)) / (A + A);
	if ((PROJ = vector_dist(o->origin, vector_projection(o->origin,
						o->direction, ADD(r->pos, MUL(r->dir,
							RES_1))))) >= o->height)
		return (MAX_SIZE);
	return (RES_1 < RES_2 ? RES_1 : RES_2);
}

t_vector4f	cylinder_normal(t_object *o, t_ray ray)
{
	return (vector_normalize(SUB(SUB(ray.pos, o->origin), MUL(o->direction,
						vector_dot(SUB(ray.pos, o->origin), o->direction)))));
}
