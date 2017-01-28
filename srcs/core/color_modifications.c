/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:13 by telain            #+#    #+#             */
/*   Updated: 2017/01/28 18:00:54 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>

int			adjust_color(t_scene *s, t_object *hit, t_ray ray)
{
	t_vector4f	light;
	float		coef;
	int			c;

	c = s->background;
	light = vector_normalize(SUB(((t_object*)s->lights->content)->origin, ray.pos));
	coef = 1.0;
	if (hit != 0)
	{
		coef = vector_dot(light, get_normal(hit, ray));
		coef *= find_shadow(s, hit, ray, light);
		c = color_mul(hit->color, coef);
	}
	return (c);
}
