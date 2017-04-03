/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersecion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:56:24 by telain            #+#    #+#             */
/*   Updated: 2017/04/03 10:37:04 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#define	CAP_1 caps[0]
#define	CAP_2 caps[1]

static void	sub_get_inter_1(t_object *obj,
	t_ray *r, float *c, t_object **hit)
{
	float	d;
	d = 0;

	d = (obj->type == SPHERE) ? (find_sphere_inter(r, obj)) : (d);
	d = (obj->type == PLANE) ? (find_plane_inter(r, obj)) : (d);
	d = (obj->type == CONE) ? (find_cone_inter(r, obj)) : (d);
	d = (obj->type == RECTANGLE) ? (find_rectangle_inter(r, obj)) : (d);
	d = (obj->type == CIRCLE) ? (find_circle_inter(r, obj)) : (d);
	d = (obj->type == TRIANGLE) ? (find_triangle_inter(r, obj)) : (d);
	if ((d < *c) && (d >= 0.001))
	{
		*hit = obj;
		*c = d;
	}
}

static void sub_get_inter_2(t_object *obj,
	t_ray *ray, float *c, t_object **hit)
{
	float		d;

	d = 0;
	if ((d = find_circle_inter(ray, obj->bot_cap)) < *c && d >= 0.001)
	{
		*hit = obj->bot_cap;
		*c = d;
	}
	if ((d = find_circle_inter(ray, obj->top_cap)) < *c && d >= 0.001)
	{
		*hit = obj->top_cap;
		*c = d;
	}
	if ((d = find_cylinder_inter(ray, obj)) < *c && d >= 0.001)
	{
		*hit = obj;
		*c = d;
	}
}

t_object	*get_intersection(t_scene *s, t_ray *ray)
{
	t_list		*obj;
	t_object	*hit;
	float		closest;

	obj = s->objects;
	closest = MAX_SIZE;
	hit = NULL;
	while (obj != 0)
	{
		if (((t_object*)obj->content)->type == CYLINDER)
			sub_get_inter_2(((t_object*)obj->content), ray, &closest, &hit);
		else
			sub_get_inter_1(((t_object*)obj->content), ray, &closest, &hit);
		obj = obj->next;
	}
	ray->pos = ADD(ray->pos, MUL(ray->dir, closest - 0.001));
	return (hit);
}
