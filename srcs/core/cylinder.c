/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:04:35 by svassal           #+#    #+#             */
/*   Updated: 2017/02/07 20:55:34 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <vector.h>
#include <ray.h>
#define A		f[0]
#define B		f[1]
#define C		f[2]
#define D		f[3]
#define RES_0	f[4]
#define RES_1	f[5]

/*
 ** Check if the ray intersects with the cylinder given as parameter
 */

float		find_cylinder_inter(t_ray *r, t_object *o)
{
	float		f[6];

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
	RES_0 = (-B - sqrtf(D)) / (A + A);
	RES_1 = (-B + sqrtf(D)) / (A + A);
	return (find_cylinder_end(r, o, RES_0 < RES_1 ? RES_0 : RES_1,
				RES_0 < RES_1 ? RES_1 : RES_0));
}

t_vector4f	cylinder_normal(t_object *o, t_ray ray)
{
	return (vector_normalize(SUB(SUB(ray.pos, o->origin), MUL(o->direction,
						vector_dot(SUB(ray.pos, o->origin), o->direction)))));
}

float		find_cap(t_ray *r, t_object *o, float r1, float r2)
{
	t_vector4f	projection1;
	t_vector4f	projection2;
	t_object	bot_cap;
	t_object	top_cap;
	float		dist1;
	float		dist2;

	top_cap.origin = ADD(o->origin, MUL(o->direction, o->end));
	bot_cap.origin = ADD(o->origin, MUL(o->direction, -o->start));
	top_cap.direction = o->direction;
	bot_cap.direction = MUL(o->direction, -1);
	projection1 = vector_projection(o->origin, o->direction, ADD(r->pos, MUL(r->dir, r1)));
	projection2 = vector_projection(o->origin, o->direction, ADD(r->pos, MUL(r->dir, r2)));
	dist1 = vector_dist(projection1, o->origin);
	dist2 = vector_dist(projection2, o->origin);
	if (dist1 > o->end)
	{
		if (dist2 > o->start)
			return (MAX_SIZE);
		else
			return (find_plane_inter(r, &bot_cap));
	}
	return (r1 < r2 ? r1 : r2);
}
