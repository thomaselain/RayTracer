/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:23:02 by telain            #+#    #+#             */
/*   Updated: 2017/03/21 12:40:12 by telain           ###   ########.fr       */
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
	return (hit->color);
}

unsigned int		find_plane_texture(t_object *o, t_ray ray)
{
	float		d;
	t_vector4f	up;
	t_vector4f	inter;
	t_vector4f	u;
	t_vector4f	v;

	up = (t_vector4f){0, 0.0000001, -1, 0};	
	u = vector_cross(o->direction, up);
	v = vector_cross(o->direction, u);
	if (o->type == PLANE)
		d = find_plane_inter(&ray, o);
	else
		d = find_rectangle_inter(&ray, o);
	inter = ADD(ray.pos, MUL(ray.dir, d));
	return (img_get_pixel(&o->texture,
				(int)(vector_dist(vector_projection(o->origin, u, inter), o->origin)) % o->texture.w,
				o->texture.h - ((int)(vector_dist(vector_projection(o->origin, v, inter),
					o->origin) + o->texture.w) % o->texture.h)));
}

unsigned int		find_sphere_texture(t_object *o, t_ray ray)
{
	float		u;
	float		v;
	t_vector4f	p;

	p = vector_normalize(SUB(ray.pos, o->origin));
	u = 0.5 + atan2(p.x, p.y) / (M_PI + M_PI);
	v = 0.5 - asin(-p.z) / M_PI;
	return (img_get_pixel(&o->texture,
				u * o->texture.w,
				v * o->texture.h));
}
