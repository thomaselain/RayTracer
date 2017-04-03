/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:32:35 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 17:58:23 by svassal          ###   ########.fr       */
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

// float		find_cone_inter(t_ray *r, t_object *o)
// {
// 	float		f[6];

// 	A = vector_dot(r->dir, r->dir) - powf(vector_dot(r->dir,
// 		o->direction), 2) * (1 + powf(tanf(o->angle / 2), 2));
// 	B = 2 * ((vector_dot(r->dir, vector_sub_vec(r->pos, o->origin))) -
// 		(1 + powf(tanf(o->angle / 2), 2)) * vector_dot(r->dir,
// 			o->direction) * vector_dot(vector_sub_vec(r->pos, o->origin),
// 				o->direction));
// 	C = vector_dot(vector_sub_vec(r->pos, o->origin), vector_sub_vec(
// 		r->pos, o->origin)) - (1 + powf(tanf(o->angle / 2), 2)) *
// 			powf(vector_dot(vector_sub_vec(r->pos, o->origin),
// 				o->direction), 2);
// 	D = powf(B, 2) - 4 * A * C;
// 	if (D < 0.0)
// 		return (MAX_SIZE);
// 	RES_0 = (-B - sqrtf(D)) / (A + A);
// 	RES_1 = (-B + sqrtf(D)) / (A + A);
// 	if (vector_dist(o->origin, vector_projection(o->origin, o->direction, ADD(r->pos, MUL(r->dir, RES_0)))) > o->height)
// 		return (MAX_SIZE);
// 	return (RES_0 < RES_1 ? RES_0 : RES_1);
// }

// void		apply_transfo(t_ray *tmp, t_object *o, int index)
// {
// 	if (index == 1)
// 	{
// 		;// appliquer transformations normales
// 	}
// 	else if (index == -1)
// 	{
// 		;// appliquer transformations inverses
// 	}
// }

float		find_cone_inter(t_ray *r, t_object *o)
{
	// t_ray	*tmp_ray; // Pour se servir de la methode de seb
	// t_ray	*ret_ray;
	float	f[7];
	float	tan_alpha;

	// tmp_ray = r;
	// apply_transfo(tmp_ray, o, -1); // On applique les transformations inverses sur le rayon (on prend -1 en parametre pour les transformations inverses, 1 sinon)
	// printf("%0.3f\n", o->angle);
	tan_alpha = powf(tanf(o->angle / 2), 2);
	A = (r->dir.x * r->dir.x) + (r->dir.z * r->dir.z) - tan_alpha * (r->dir.y * r->dir.y);
	B = (2 * r->pos.x * r->dir.x) + (2 * r->pos.z * r->dir.z) - (2 * tan_alpha * r->pos.y * r->dir.y);
	C = powf(r->pos.x, 2) + powf(r->pos.z, 2) - tan_alpha * powf(r->pos.y, 2);
	D = powf(B, 2) - 4 * A * C;
	if (D < 0.0)
		return (MAX_SIZE);
	RES_0 = (-B - sqrtf(D)) / (A + A);
	RES_1 = (-B + sqrtf(D)) / (A + A);
	if (vector_dist(o->origin, vector_projection(o->origin, o->direction,
		ADD(r->pos, MUL(r->dir, RES_0)))) > o->height)
		return (MAX_SIZE);
	return (RES_0 < RES_1 ? RES_0 : RES_1);
}




// float		find_cone_inter(t_ray *r, t_object *o)
// {
// 	float		f[6];
// 	float		tan_alpha;
	
// 	tan_alpha = powf(tanf(o->angle / 2), 2);
// 	A = (r->dir.x * r->dir.x) + (r->dir.z * r->dir.z) - tan_alpha * (r->dir.y * r->dir.y);
// 	B = (2 * r->pos.x * r->dir.x) + (2 * r->pos.z * r->dir.z) - (2 * tan_alpha * r->pos.y * r->dir.y);
// 	C = powf(r->pos.x, 2) + powf(r->pos.z, 2) - tan_alpha * powf(r->pos.y, 2);
// 	D = powf(B, 2) - 4 * A * C;
// 	if (D > 0.0)
// 	{
// 		RES_0 = (-B - sqrtf(D)) / (A + A);
// 		RES_1 = (-B + sqrtf(D)) / (A + A);
// 		if (RES_0 > 0)
// 			return (RES_0);
// 		else
// 			return (RES_1);
// 	}
// 	else
// 		return (-1);
// }

t_vector4f		cone_normal(t_object *o, t_ray ray)
{
	t_vector4f	ret;
	t_vector4f	inter;
	float		tan_alpha;

	// printf("%0.3f\n", o->angle);
	if (o->top_cap->radius <= 0 && o->top_cap->radius <= 0) // On definit la taille des caps, j'ai mis ca la parce que je savais pas ou le mettre autrement :)
	{
		o->top_cap->radius = tanf(o->angle / 2) * (vector_dot(ray.dir, vector_mul_flo(o->direction, find_cone_inter(&ray, o))) + vector_dot(vector_sub_vec(ray.pos, o->origin), o->direction));
		o->bot_cap->radius = tanf(o->angle / 2) * (vector_dot(ray.dir, vector_mul_flo(o->direction, find_cone_inter(&ray, o))) + vector_dot(vector_sub_vec(ray.pos, o->origin), o->direction));
	}
	tan_alpha = powf(tanf(o->angle / 2), 2);
	inter = vector_add_vec(ray.pos, vector_mul_flo(ray.dir, find_cone_inter(&ray, o)));
	ret.x = 2 * inter.x;
	ret.y = -2 * tan_alpha * inter.y;
	ret.z = 2 * inter.z;
	ret.w = 0;
	vector_normalize(ret);
	// printf("%0.3f\n", o->top_cap->radius);
	return (ret);
}


// t_vector4f	cone_normal(t_object *o, t_ray ray)
// {
// 	t_vector4f	v1;
// 	t_vector4f	v2;

// 	v1 = DIV(SUB(ray.pos, o->origin), vector_dot(SUB(ray.pos, o->origin),
// 				o->direction));
// 	v2 = MUL(o->direction, 2);
// 	if (vector_dot(o->direction, SUB(ray.pos, o->origin)) < 0)
// 		return (SUB(v2, v1));
// 	else
// 		return (SUB(v1, v2));
// 	return (v1);
// }
