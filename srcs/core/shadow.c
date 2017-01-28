/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:29:56 by telain            #+#    #+#             */
/*   Updated: 2017/01/28 18:26:01 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <color.h>

float	find_shadow(t_scene *s, t_object *hit, t_ray ray, t_vector4f light)
{
	ray.pos = SUB(ray.pos, MUL(vector_normalize(SUB(light, ray.pos)), 0.1));
	ray.dir = vector_normalize(SUB(light, ray.pos));
	if (get_intersection(s, &ray) != NULL)
		return (0);
	return (1);
}
