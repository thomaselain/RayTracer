/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:41:59 by telain            #+#    #+#             */
/*   Updated: 2017/03/05 20:55:18 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_triangle_inter(t_ray *r, t_object *o)
{
	float		d;
	t_vector4f	n;
	t_vector4f	inter;
	t_vector4f	C;
	t_vector4f	edge0;
	t_vector4f	vp0;
	t_vector4f	edge1;
	t_vector4f	vp1;
	t_vector4f	edge2;
	t_vector4f	vp2;

	n = vector_cross(vector_sub_vec(o->som1, o->som0), vector_sub_vec(o->som2, o->som0));
	d = find_plane_inter(r, o);
	inter = ADD(r->pos, MUL(r->dir, d));

	edge0 = vector_sub_vec(o->som1, o->som0);
	vp0 = vector_sub_vec(inter, o->som0);
	C = vector_cross(edge0, vp0);
	if (vector_dot(n, C) < 0)
		return (0);

	edge1 = vector_sub_vec(o->som2, o->som1);
	vp1 = vector_sub_vec(inter, o->som1);
	C = vector_cross(edge1, vp1);
	if (vector_dot(n, C) < 0)
		return (0);

	edge2 = vector_sub_vec(o->som0, o->som2);
	vp2 = vector_sub_vec(inter, o->som2);
	C = vector_cross(edge2, vp2);
	if (vector_dot(n, C) < 0)
		return (0);

	return (find_plane_inter(r, o));
}
