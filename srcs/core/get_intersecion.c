/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersecion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:56:24 by telain            #+#    #+#             */
/*   Updated: 2017/04/02 23:34:21 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#define	CAP_1 caps[0]
#define	CAP_2 caps[1]

static void	sub_get_inter_1(t_object *obj,
	t_ray *r, float *c, t_object **hit)
{
	float	d[6];

	d[0] = find_sphere_inter(r, obj);
	d[1] = find_plane_inter(r, obj);
	d[2] = find_cone_inter(r, obj);
	d[3] = find_rectangle_inter(r, obj);
	d[4] = find_circle_inter(r, obj);
	d[5] = find_triangle_inter(r, obj);
	if (((d[0] < *c) && (d[0] >= 0.001)) || ((d[1] < *c) && (d[1] >= 0.001)) ||
		((d[2] < *c) && (d[2] >= 0.001)) || ((d[3] < *c) && (d[3] >= 0.001)) ||
		((d[4] < *c) && (d[4] >= 0.001)) || ((d[5] < *c) && (d[5] >= 0.001)))
	{
		*hit = obj;
		*c = (obj->type == SPHERE) ? (d[0]) : (*c);
		*c = (obj->type == PLANE) ? (d[1]) : (*c);
		*c = (obj->type == CONE) ? (d[2]) : (*c);
		*c = (obj->type == RECTANGLE) ? (d[3]) : (*c);
		*c = (obj->type == CIRCLE) ? (d[4]) : (*c);
		*c = (obj->type == TRIANGLE) ? (d[5]) : (*c);
	}
}

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
		// if (((t_object*)obj->content)->type == SPHERE && (d =
		// 			find_sphere_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		// else if (((t_object*)obj->content)->type == PLANE && (d =
		// 			find_plane_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		// else if (((t_object*)obj->content)->type == CONE && (d =
		// 			find_cone_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		// else if (((t_object*)obj->content)->type == RECTANGLE && (d =
		// 			find_rectangle_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		// else if (((t_object*)obj->content)->type == CIRCLE && (d =
		// 			find_circle_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		// else if (((t_object*)obj->content)->type == TRIANGLE && (d =
		// 			find_triangle_inter(ray, (t_object*)obj->content)) <
		// 		closest && d >= 0.001)
		// {
		// 	hit = (t_object*)obj->content;
		// 	closest = d;
		// }
		if (((t_object*)obj->content)->type == CYLINDER)
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
		else
			sub_get_inter_1(((t_object*)obj->content), ray, &closest, &hit);
		obj = obj->next;
	}
	ray->pos = ADD(ray->pos, MUL(ray->dir, closest - 0.001));
	return (hit);
}
