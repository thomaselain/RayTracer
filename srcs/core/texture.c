/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:23:02 by telain            #+#    #+#             */
/*   Updated: 2017/03/23 15:00:33 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>
#include <img.h>
#define	NORMAL(X) vector_normalize(X)
#define ROTATE(X, Y, Z) vector_rotate(X, Y, Z)

unsigned int		get_texture_pixel(t_object *hit, t_ray ray)
{
	if (hit->type == PLANE || hit->type == RECTANGLE)
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
	u = o->radius / (2 * M_PI * o->radius) * (theta + o->height);
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
	t = vector_normalize(t);
	d = vector_dist(ray.pos, o->origin);
	alpha = acos(vector_dot(t, vector_normalize(SUB(o->origin, ray.pos))));
	u = cos(alpha) * d / 50;
	v = sin(alpha) * d / 50;
//	u = u < 0 ? -u : u;
	v = v < 0 ? 1 + v : v;
	return (img_get_pixel(&o->texture,
				(int)(u * o->texture.w) % o->texture.w,
				(int)(v * o->texture.h) % o->texture.h));
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
