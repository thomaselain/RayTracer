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

t_object	*get_intersection(t_list *obj, t_ray *ray)
{
	t_object	*hit;
	float		closest;

	closest = MAX_SIZE;
	hit = NULL;
	while (obj != 0)
	{
		if (((t_object*)obj->content)->type == SPHERE)
			closest = call_sphere(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == PLANE)
			closest = call_plane(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == CYLINDER)
			closest = call_cyl(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == CONE)
			closest = call_cone(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == RECTANGLE)
			closest = call_rect(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == CIRCLE)
			closest = call_circle(ray, obj, closest, &hit);
		else if (((t_object*)obj->content)->type == TRIANGLE)
			closest = call_tri(ray, obj, closest, &hit);
		obj = obj->next;
	}
	ray->pos = ADD(ray->pos, MUL(ray->dir, closest - 0.001));
	return (hit);
}
