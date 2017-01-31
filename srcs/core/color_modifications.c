/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:13 by telain            #+#    #+#             */
/*   Updated: 2017/01/31 16:31:51 by telain           ###   ########.fr       */
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
		c = hit->color;
		if (vector_dot(light, get_normal(hit, ray)) >= 0)
			c = color_mul(c, vector_dot(light, get_normal(hit, ray)));
		else
			c = 0;
		coef *= find_shadow(s, hit, ray, light);
		if (hit->type == PLANE)
			return (color_mul(hit->color, coef));
		//		c = color_add(hit->color, color_mul(((t_object*)s->lights->content)->color, specular_light(s, hit, ray, light)));           //Work in progress :/
		c = color_mul(c, coef);
	}
	return (c);
}
