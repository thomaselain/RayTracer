/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:10:44 by telain            #+#    #+#             */
/*   Updated: 2017/04/17 15:33:50 by telain           ###   ########.fr       */
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
	closest = MAX_SIZE;
	hit = NULL;
	d = 0;
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
		else if (((t_object*)obj->content)->type == CONE)
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
			if ((d = find_cone_inter(ray, (t_object*)obj->content)) < closest && d >= 0.001)
			{
				hit = (t_object*)obj->content;
				closest = d;
			}
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
