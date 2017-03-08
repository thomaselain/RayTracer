/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersecion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:56:24 by telain            #+#    #+#             */
/*   Updated: 2017/03/02 19:41:11 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#define	CAP_1 caps[0]
#define	CAP_2 caps[1]

t_object	*get_intersection(t_scene *s, t_ray *ray)
{
	t_list		*obj;
	t_object	*hit;
	float		closest;
	float		d;

	obj = s->objects;
	closest = MAX_SIZE;
	hit = NULL;
	while (obj != 0)
	{
		if (((t_object*)obj->content)->type == SPHERE && (d =
					find_sphere_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		else if (((t_object*)obj->content)->type == PLANE && (d =
					find_plane_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		else if (((t_object*)obj->content)->type == CYLINDER)
		{
			if ((d = find_circle_inter(ray, ((t_object*)obj->content)->bot_cap)) < closest && d >= 0.001)
			{
				hit = ((t_object*)obj->content)->bot_cap;
				closest = d;
			}
			if ((d = find_circle_inter(ray, ((t_object*)obj->content)->top_cap)) < closest && d >= 0.001)
			{
				hit = ((t_object*)obj->content)->top_cap;
				closest = d;
			}
		if ((d = find_cylinder_inter(ray, (t_object*)obj->content)) < closest && d >= 0.001)
			{
				hit = (t_object*)obj->content;
				closest = d;
			}
		}
		else if (((t_object*)obj->content)->type == CONE && (d =
					find_cone_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		else if (((t_object*)obj->content)->type == RECTANGLE && (d =
					find_rectangle_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		else if (((t_object*)obj->content)->type == CIRCLE && (d =
					find_circle_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		else if (((t_object*)obj->content)->type == TRIANGLE && (d =
					find_triangle_inter(ray, (t_object*)obj->content)) <
				closest && d >= 0.001)
		{
			hit = (t_object*)obj->content;
			closest = d;
		}
		obj = obj->next;
	}
	ray->pos = ADD(ray->pos, MUL(ray->dir, closest - 0.001));
	return (hit);
}
