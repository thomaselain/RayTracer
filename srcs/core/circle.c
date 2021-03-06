/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:37:37 by telain            #+#    #+#             */
/*   Updated: 2017/04/19 16:53:25 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_circle_inter(t_ray *r, t_object *o)
{
	float	d;

	d = find_plane_inter(r, o);
	return (vector_dist(o->origin, ADD(r->pos, MUL(r->dir, d - 0.001))) <
		o->rad_int.radius ? d : MAX_SIZE);
}

float		call_circle(t_ray *ray, t_list *obj, float closest, t_object **hit)
{
	float	ret;

	ret = find_circle_inter(ray, (t_object*)obj->content);
	if (ret < closest && ret >= 0.001)
	{
		*hit = (t_object*)obj->content;
		return (ret);
	}
	else
		return (closest);
}
