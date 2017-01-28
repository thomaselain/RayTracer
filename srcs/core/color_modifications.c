/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:13 by telain            #+#    #+#             */
/*   Updated: 2017/01/28 15:58:15 by telain           ###   ########.fr       */
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
	int			ret;

	light = vector_normalize(SUB(((t_object*)s->lights->content)->origin, ray.pos));
	ret = 0;
	coef = 1.0;
	if (hit != 0)
	{
		coef = vector_dot(light, get_normal(hit, ray));
//		coef *= hit->type == PLANE ? 1.25 : 1.0;
//		coef -= find_shadow(s, hit, ray, light);
		ret = color_mul(hit->color, coef);
	}
	return (ret);
}
