/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications_recursive.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:42:04 by telain            #+#    #+#             */
/*   Updated: 2017/03/19 13:33:31 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>


int		adjust_color(t_scene *s, t_object *hit, t_ray ray, int reflects)
{
	unsigned int	c;
	float			n;
	t_ray			ray_cpy;
	t_object		*tmp_hit;
	t_list			*light;

	light = s->lights;
	c = s->background;
	ray_cpy = ray;
	while (light != 0)
	{
		if (hit != 0)
			c = color_add(c, compute_light(s, hit, ray, (t_object*)light->content));
		light = light->next;
	}
	if (hit != 0 && hit->reflection > 0.0 && reflects <= MAX_REFLECTION)
	{
		n = noise(hit, MUL(ray.pos, 0.1));
		tmp_hit = get_reflect(s, hit, &ray);
		c = color_add(color_mul(adjust_color(s, tmp_hit, ray, reflects + 1),
					hit->reflection), c);
	}
	if (hit != 0 && hit->transparence > 0.0 && reflects <= MAX_REFLECTION)
	{
		n = noise(hit, MUL(ray_cpy.pos, 0.1));
		tmp_hit = get_refract(s, hit, &ray_cpy);
		c = color_add(color_mul(adjust_color(s, tmp_hit, ray_cpy, reflects + 1),
					hit->transparence),
				color_mul(c, 1 - hit->transparence));
	}
	return (c);
}

t_object	*get_refract(t_scene *s, t_object *hit, t_ray *ray)
{
	t_vector4f	normal;
	float		angle;

	if (hit->refraction > 1.0)
	{
		normal = get_normal(hit, *ray);
		angle = vector_dot(ray->dir, normal);
		ray->dir = vector_normalize(ADD(MUL(ray->dir, 1.0 / hit->refraction),
					MUL(normal, 1.0 / hit->refraction * angle -  sqrt(1.0 -
							pow(1.0 / hit->refraction, 2.0)	* (1.0 -
								pow(angle, 2.0))))));
	}
	else
		ray->pos = ADD(ray->pos, MUL(ray->dir, 0.001));
	return (get_intersection(s, ray));
}

t_object	*get_reflect(t_scene *s, t_object *hit, t_ray *ray)
{
	t_vector4f	normal;

	normal = get_normal(hit, *ray);
	ray->dir = ADD(ray->dir, MUL(normal, -2.0 * vector_dot(normal, ray->dir)));
	return (get_intersection(s, ray));
}

unsigned int	compute_light(t_scene *s, t_object *o, t_ray ray, t_object *light)
{
	unsigned int	c;
	t_ray			v_light;
	t_ray			specular;

	c = o->color; //peut etre a mettre en haut
	v_light.pos = light->origin;
	v_light.dir = get_light_vector(light, ray);
	specular = ray;
	get_reflect(s, o, &specular);
	// if (o->brightness > 0.0)
	// 	c = color_add(c, color_mul(light->color, - 1 * pow(vector_dot(v_light.dir, specular.dir), o->brightness)));
	if (vector_dot(v_light.dir, get_normal(o, ray)) >= 0)
		c = color_mul(c, vector_dot(v_light.dir, get_normal(o, ray)));
	else
		c = 0;
	c = color_mul(c, find_shadow(s, o, ray, v_light) * noise(o, ray.pos));
	return (c);
}
