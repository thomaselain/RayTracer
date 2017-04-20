/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:41:59 by telain            #+#    #+#             */
/*   Updated: 2017/04/05 19:38:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <matrix.h>
#define NORMAL(X) vector_normalize(X)
#define ROTATE(X, Y, Z) vector_rotate(X, Y, Z)

float		find_rectangle_inter(t_ray *r, t_object *o)
{
	float		d;
	t_vector4f	u;
	t_vector4f	v;
	t_vector4f	up;
	t_vector4f	inter;

	up = (t_vector4f){0, 0.000000001, -1, 0};
	up = NORMAL(ROTATE(up, o->direction, o->rotation));
	u = vector_cross(o->direction, up);
	v = vector_cross(u, o->direction);
	d = find_plane_inter(r, o);
	inter = ADD(r->pos, MUL(r->dir, d));
	if (vector_dist(vector_projection(o->origin, u, inter),
		o->origin) > o->width / 2 || vector_dist(vector_projection(o->origin,
			v, inter), o->origin) > o->height / 2)
		return (MAX_SIZE);
	return (d);
}

float		call_rect(t_ray *ray, t_list *obj, float closest, t_object **hit)
{
	float	ret;

	ret = find_rectangle_inter(ray, (t_object*)obj->content);
	if (ret < closest && ret >= 0.001)
	{
		*hit = (t_object*)obj->content;
		return (ret);
	}
	else
		return (closest);
}
