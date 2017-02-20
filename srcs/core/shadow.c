/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:29:56 by telain            #+#    #+#             */
/*   Updated: 2017/02/16 17:32:01 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>

float	find_shadow(t_scene *s, t_object *hit, t_ray ray, t_ray light)
{
	t_vector4f	before;

	before = ray.pos;
	ray.pos = ADD(ray.pos, MUL(light.dir, 0.001));
	ray.dir = light.dir;
	if (get_intersection(s, &ray) != NULL && vector_dist(before, ray.pos) <= vector_dist(before, light.pos))
		return (0.3);
	return (1);
}

float	specular_light(t_scene *s, t_object *hit, t_ray ray, t_vector4f light)
{
	float		specular;
	t_vector4f	reflect;

	if (vector_dot(get_normal(hit, ray), light) <= 0)
		return (0);
	else
	{
		reflect = SUB(ray.dir, MUL(get_normal(hit, ray), -2.0 * vector_dot(get_normal(hit, ray), ray.dir)));
		specular = vector_dot(light, reflect);
	}
	/*
	   specular = pow(vector_dot(MUL(light, -1),
	   ADD(vector_cross(ray.dir, get_normal(hit, ray)),
	   SUB(MUL(ray.dir, -1), MUL(get_normal(hit, ray),
	   2 * vector_dot(MUL(ray.dir, -1), get_normal(hit, ray)))))),
	   hit->diffuse);
	   */
	return (specular >= 1.0 ? 1.0 : specular);
}

t_vector4f	get_light_vector(t_object *light, t_ray ray)
{
	if (light->type == SPOT)
		return (vector_normalize(SUB(light->origin, ray.pos)));
	return (vector_normalize(light->direction));
}
