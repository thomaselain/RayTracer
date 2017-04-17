/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:32:35 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 17:08:49 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <vector.h>
#include <ray.h>
#define A			f[0]
#define B			f[1]
#define C			f[2]
#define D			f[3]
#define RES_0		f[4]
#define RES_1		f[5]
#define RES			f[6]

/*
** Check if the ray intersects with the cone given as parameter
*/

float		find_cone_inter(t_ray *r, t_object *o)
{
	float		f[6];

	A = vector_dot(r->dir, r->dir) - powf(vector_dot(r->dir,
				o->direction), 2) * (1 + powf(tanf(o->angle / 2), 2));
	B = 2 * ((vector_dot(r->dir, vector_sub_vec(r->pos, o->origin))) -
			(1 + powf(tanf(o->angle / 2), 2)) * vector_dot(r->dir,
				o->direction) * vector_dot(vector_sub_vec(r->pos, o->origin),
					o->direction));
	C = vector_dot(vector_sub_vec(r->pos, o->origin), vector_sub_vec(
				r->pos, o->origin)) - (1 + powf(tanf(o->angle / 2), 2)) *
		powf(vector_dot(vector_sub_vec(r->pos, o->origin),
					o->direction), 2);
	D = powf(B, 2) - 4 * A * C;
	if (D < 0.0)
		return (MAX_SIZE);
	RES_0 = (-B - sqrtf(D)) / (A + A);
	RES_1 = (-B + sqrtf(D)) / (A + A);
	if (vector_dist(o->origin, vector_projection(o->origin, o->direction,
					ADD(r->pos, MUL(r->dir, RES_0)))) > o->height)
		return (MAX_SIZE);
	return (RES_0);
}
/*
t_vector4f		cone_normal(t_object *o, t_ray ray)
{
	t_vector4f	ret;
	t_vector4f	inter;
	float		tan_alpha;

	if (o->top_cap->radius <= 0 && o->top_cap->radius <= 0)
	{
		o->top_cap->radius = tanf(o->angle / 2) * (vector_dot(ray.dir,
					vector_mul_flo(o->direction, find_cone_inter(&ray, o))) +
				vector_dot(vector_sub_vec(ray.pos, o->origin), o->direction));
		o->bot_cap->radius = tanf(o->angle / 2) * (vector_dot(ray.dir,
					vector_mul_flo(o->direction, find_cone_inter(&ray, o))) +
				vector_dot(vector_sub_vec(ray.pos, o->origin), o->direction));
	}
	tan_alpha = powf(tanf(o->angle / 2), 2);
	inter = vector_add_vec(ray.pos, vector_mul_flo(ray.dir,
				find_cone_inter(&ray, o)));
	ret.x = (inter.x - o->origin.x) * (o->height / o->angle);
	ret.y = o->angle / o->height;
	ret.z = (inter.z - o->origin.z) * (o->height / o->angle);
	ret.w = 0;
	return (vector_normalize(ret));
}
*/
t_vector4f	cone_normal(t_object *o, t_ray ray)
{
	t_vector4f	v1;
	t_vector4f	v2;

	v1 = DIV(SUB(ray.pos, o->origin), vector_dot(SUB(ray.pos, o->origin),
				o->direction));
	v2 = MUL(o->direction, 2);
	if (vector_dot(o->direction, SUB(ray.pos, o->origin)) < 0)
		return (SUB(v2, v1));
	else
		return (SUB(v1, v2));
	return (v1);
}
