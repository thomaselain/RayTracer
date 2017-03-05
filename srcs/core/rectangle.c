/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:41:59 by telain            #+#    #+#             */
/*   Updated: 2017/03/05 20:55:18 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_rectangle_inter(t_ray *r, t_object *o)
{
	float		d;
	t_vector4f	u;
	t_vector4f	v;
	t_vector4f	up;
	t_vector4f	inter;

	up = (t_vector4f){0, 0, -1, 0};
	u = vector_cross(o->direction, up);
	v = vector_cross(u, o->direction);
	d = find_plane_inter(r, o);
	inter = ADD(r->pos, MUL(r->dir, d));
	if (vector_dist(vector_projection(o->origin, u, inter), o->origin) > o->start ||
			vector_dist(vector_projection(o->origin, v, inter), o->origin) > o->end)
		return (MAX_SIZE);
	return (find_plane_inter(r, o));
}
