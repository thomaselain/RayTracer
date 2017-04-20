/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:41:59 by telain            #+#    #+#             */
/*   Updated: 2017/04/17 17:42:45 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

int				calcul_sommet(t_vector4f som0, t_vector4f som1,
		t_vector4f inter, t_vector4f n)
{
	t_vector4f	edge;
	t_vector4f	vp;
	t_vector4f	c;

	edge = vector_sub_vec(som1, som0);
	vp = vector_sub_vec(inter, som0);
	c = vector_cross(edge, vp);
	if (vector_dot(n, c) < 0)
		return (-1);
	return (0);
}

float			find_triangle_inter(t_ray *r, t_object *o)
{
	float		d;
	t_vector4f	n;
	t_vector4f	inter;

	n = vector_cross(vector_sub_vec(o->som1, o->som0),
			vector_sub_vec(o->som2, o->som0));
	d = find_plane_inter(r, o);
	inter = ADD(r->pos, MUL(r->dir, d));
	if (calcul_sommet(o->som0, o->som1, inter, n) != 0)
		return (0);
	if (calcul_sommet(o->som1, o->som2, inter, n) != 0)
		return (0);
	if (calcul_sommet(o->som2, o->som0, inter, n) != 0)
		return (0);
	return (find_plane_inter(r, o));
}

float		call_tri(t_ray *ray, t_list *obj, float closest, t_object **hit)
{
	float	ret;

	ret = find_triangle_inter(ray, (t_object*)obj->content);
	if (ret < closest && ret >= 0.001)
	{
		*hit = (t_object*)obj->content;
		return (ret);
	}
	else
		return (closest);
}
