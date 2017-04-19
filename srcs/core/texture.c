/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:23:02 by telain            #+#    #+#             */
/*   Updated: 2017/04/19 16:54:40 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>
#include <img.h>
#define NORMAL(X) vector_normalize(X)
#define ROTATE(X, Y, Z) vector_rotate(X, Y, Z)

unsigned int		get_texture_pixel(t_object *hit, t_ray ray)
{
	if (hit->type == PLANE || hit->type == RECTANGLE || hit->type == CIRCLE)
		return (find_plane_texture(hit, ray));
	if (hit->type == SPHERE)
		return (find_sphere_texture(hit, ray));
	if (hit->type == CYLINDER)
		return (find_cylinder_texture(hit, ray));
	return (hit->color);
}

unsigned int		find_cylinder_texture(t_object *o, t_ray ray)
{
	float	u;
	float	v;
	float	theta;
	float	h;

	theta = atan(ray.pos.y / ray.pos.x);
	h = ray.pos.z;
	u = o->rad_int.radius / (2 * M_PI * o->rad_int.radius * o->texture.scale) *
		(theta + o->height);
	v = 1 / (o->height * 2) * (h + o->height);
	return (img_get_pixel(&o->texture,
				u * o->texture.w,
				v * o->texture.h));
}

unsigned int		find_plane_texture(t_object *o, t_ray ray)
{
	float		u;
	float		v;
	float		d;
	float		alpha;
	t_vector4f	t;

	t = vector_cross(o->direction, (t_vector4f){0, 1, 0, 0});
	if (!vector_length(t))
		t = vector_cross(o->direction, (t_vector4f){0, 0, 1, 0});
	t = vector_mul_flo(t, -1);
	t = vector_normalize(t);
	d = vector_dist(ray.pos, o->origin);
	alpha = acos(vector_dot(t, vector_rotate(vector_normalize(SUB(o->origin,
		ray.pos)), o->direction, 0)));
	u = cos(alpha) * d / o->texture.scale;
	if (ray.pos.z < 0)
		v = sin(-alpha) * d / o->texture.scale;
	else
		v = sin(alpha) * d / o->texture.scale;
	v += MAX_SIZE;
	return (img_get_pixel(&o->texture,
				(int)(u * o->texture.w + 1) % o->texture.w,
				(int)(v * o->texture.h + 1) % o->texture.h));
}

unsigned int		find_sphere_texture(t_object *o, t_ray ray)
{
	float		u;
	float		v;
	t_vector4f	p;

	p = vector_normalize(SUB(ray.pos, o->origin));
	u = 0.5 + atan2(p.x, p.y) / (M_PI + M_PI + 0.5);
	v = 0.5 - asin(-p.z) / M_PI;
	return (img_get_pixel(&o->texture,
				u * o->texture.w,
				v * o->texture.h));
}
