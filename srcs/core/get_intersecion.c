/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersecion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:56:24 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 20:41:49 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

t_object	*get_intersection(t_scene *s, t_ray *ray)
{
	t_list		*obj;
	t_object	*hit;
	float		closest;
	float		d;

	obj = s->objects;
	closest = 100000.0;
	hit = NULL;
	while (obj != 0)
	{
		if (((t_object*)obj->content)->type == SPHERE && (d =
					find_sphere_inter(s, ray, (t_object*)obj->content)) <
				closest)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		obj = obj->next;
	}
	ray->pos = ADD(s->camera.origin, MUL(ray->dir, closest - 0.1));
	return (hit);
}
