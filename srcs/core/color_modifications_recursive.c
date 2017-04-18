/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications_recursive.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:42:04 by telain            #+#    #+#             */
/*   Updated: 2017/04/17 17:41:26 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>

int				adjust_color(t_scene *s, t_object *h, t_ray r, int ref)
{
	unsigned int	c;
	float			n;
	t_ray			r_cpy;
	t_object		*tmp_h;
	t_list			*l;

	l = s->lights;
	c = 0;
	r_cpy = r;
	if (l == 0 && h != 0)
		c = color_add(c, compute_light(s, h, r, NULL));
	else if (l == 0)
		c = s->background;
	while (l != 0)
	{
		c = (h != 0 ? color_add(c, compute_light(s, h, r,
			(t_object*)l->content)) : s->background);
		l = l->next;
	}
	if (h != 0 && h->reflection > 0.0 && ref <= MAX_REFLECTION)
	{
		n = noise(h, MUL(r.pos, 0.1));
		tmp_h = get_reflect(s, h, &r);
		c = color_add(color_mul(adjust_color(s, tmp_h, r, ref + 1),
					h->reflection), c);
	}
	if (h != 0 && h->transparence > 0.0 && ref <= MAX_REFLECTION)
	{
		n = noise(h, MUL(r_cpy.pos, 0.1));
		tmp_h = get_refract(s, h, &r_cpy);
		c = color_add(color_mul(adjust_color(s, tmp_h, r_cpy, ref + 1),
			h->transparence), color_mul(c, 1 - h->transparence));
	}
	return (c);
}

t_object		*get_reflect(t_scene *s, t_object *hit, t_ray *ray)
{
	t_vector4f	normal;

	normal = get_normal(hit, *ray);
	ray->dir = ADD(ray->dir, MUL(normal, -2.0 * vector_dot(normal, ray->dir)));
	return (get_intersection(s, ray));
}

unsigned int	compute_light(t_scene *s, t_object *o, t_ray ray,
					t_object *light)
{
	unsigned int	c;
	unsigned int	backup;
	t_ray			v_light;
	t_ray			specular;

	c = o->color;
	if (o && o->texture.srf != NULL)
		c = get_texture_pixel(o, ray);
	if (light == NULL)
		return (color_add(c, color_mul(c, 0.25)));
	backup = c;
	v_light.pos = light->origin;
	v_light.dir = get_light_vector(light, ray);
	specular = ray;
	get_reflect(s, o, &specular);
	if (o->brightness > 0.0)
		c = color_add(c, color_mul(light->color, -1 *
			pow(vector_dot(v_light.dir, specular.dir), o->brightness)));
	if (vector_dot(v_light.dir, get_normal(o, ray)) >= 0)
		c = color_mul(c, vector_dot(v_light.dir, get_normal(o, ray)));
	else
		c = 0;
	c = color_mul(c, find_shadow(s, o, ray, v_light) * noise(o, ray.pos));
	return (color_add(c, color_mul(backup, 0.1)));
}
