/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:29:56 by telain            #+#    #+#             */
/*   Updated: 2017/01/31 16:31:52 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>

float	find_shadow(t_scene *s, t_object *hit, t_ray ray, t_vector4f light)
{
	ray.pos = SUB(ray.pos, MUL(light, 0.1));
	ray.dir = light;
	if (get_intersection(s, &ray) != NULL)
		return (0);
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
		reflect = SUB(ray.dir, MUL(get_normal(hit, ray), 2 * vector_dot(get_normal(hit, ray), ray.dir)));
		specular = vector_dot(light, reflect) / hit->diffuse;
	}
/*
		specular = pow(vector_dot(MUL(light, -1),
					ADD(vector_cross(ray.dir, get_normal(hit, ray)),
		SUB(MUL(ray.dir, -1), MUL(get_normal(hit, ray),
				2 * vector_dot(MUL(ray.dir, -1), get_normal(hit, ray)))))),
				hit->diffuse);
*/
		if (specular >= 1)
		return (1);
	return (specular);
}
