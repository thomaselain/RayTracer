/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:13 by telain            #+#    #+#             */
/*   Updated: 2017/01/28 00:44:01 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>

int			adjust_color(t_scene *s, t_object *hit, t_ray ray)
{
	t_vector4f	light;
	int			c;

	light = vector_normalize(SUB(((t_object*)s->lights->content)->origin, ray.pos));
	c = 0;
	if (hit != 0)
	{
		c = hit->color;
		c = color_mul(c, vector_dot(light, get_normal(hit, ray)));
		c = hit->type == PLANE ? color_mul(c, 1.5) : c;
		c = color_sub(c, find_shadow(s, hit, ray, light));
	}
	return (c);
}
