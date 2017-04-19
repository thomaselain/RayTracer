/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:11:45 by telain            #+#    #+#             */
/*   Updated: 2017/04/18 12:25:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>

float			find_shadow(t_scene *s, t_object *hit, t_ray ray, t_ray light)
{
	t_vector4f	before;
	t_object	*new_hit;

	before = ray.pos;
	ray.pos = ADD(ray.pos, MUL(light.dir, 0.001));
	ray.dir = light.dir;
	if ((new_hit = get_intersection(s, &ray)) != NULL &&
		vector_dist(before, ray.pos) <= vector_dist(before, light.pos))
	{
		if (new_hit->transparence == 0)
			return (0.3);
		else
			return (new_hit->transparence) * find_shadow(s, hit, ray, light);
	}
	return (1);
}

t_vector4f		get_light_vector(t_object *light, t_ray ray)
{
	if (light->type == SPOT)
		return (vector_normalize(SUB(light->origin, ray.pos)));
	return (vector_normalize(light->direction));
}
