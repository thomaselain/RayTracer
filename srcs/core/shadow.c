/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:29:56 by telain            #+#    #+#             */
/*   Updated: 2017/01/29 19:52:05 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>

float	find_shadow(t_scene *s, t_object *hit, t_ray ray, t_vector4f light)
{
	ray.pos = SUB(ray.pos, MUL(vector_normalize(SUB(light, ray.pos)), -0.1));
	ray.dir = vector_normalize(SUB(light, ray.pos));
	if (get_intersection(s, &ray) != NULL)
		return (0);
	return (1);
}

float	specular_light(t_scene *s, t_object *hit, t_ray ray, t_vector4f light)
{
	float	specular;

	if ((specular = vector_dot(get_normal(hit, ray), light)) < 0)
		return (0);
	else if (specular > 0)
		return (specular * hit->diffuse); //Remplacer ce nombre par une variable dans L'objet
	else
		return (0);
}
