/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:49:13 by telain            #+#    #+#             */
/*   Updated: 2017/02/05 14:30:51 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>

int			adjust_color(t_scene *s, t_object *hit, t_ray ray)
{
	t_object	*first_hit;
	t_list		*light;
	t_vector4f	v_light;
	float		coef;
	int			c;
	int			i;

	i = -1;

	c = s->background;
	coef = 1.0;
	light = s->lights;
	while (hit != 0 && hit->reflection > 0.0 && ++i <= MAX_REFLECTION)
	{
		first_hit = hit;
		hit = get_reflect(s, hit, &ray);
	}
	if (hit != 0)
	{
		c = hit->color;
		while (light != 0)
		{
			v_light = vector_normalize(SUB(((t_object*)light->content)->origin, ray.pos));
			if (vector_dot(v_light, get_normal(hit, ray)) >= 0)
				c = color_mul(c, vector_dot(v_light, get_normal(hit, ray)));
			else
				c = 0;
			coef *= find_shadow(s, hit, ray, v_light);
			if (hit->type == PLANE)
				c = find_grid_color(hit, ray);
			//c = color_add(hit->color, color_mul(((t_object*)light->content)->color, specular_light(s, hit, ray, v_light)));           //Work in progress :/
//			c = color_mul(c, coef);
			light = light->next;
		}
	}
			c = first_hit != 0 ? color_add(c, color_mul(color_avg(c, first_hit->color), 1)) : c;
	return (c);
}

t_object	*get_reflect(t_scene *s, t_object *hit, t_ray *ray)
{
	t_vector4f	normal;

	normal = get_normal(hit, *ray);
	ray->dir = ADD(ray->dir, MUL(normal, -2.0 * vector_dot(normal, ray->dir)));
	return (get_intersection(s, ray));
}
