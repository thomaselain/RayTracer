/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:41:59 by telain            #+#    #+#             */
/*   Updated: 2017/02/06 22:29:22 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_square_inter(t_ray *r, t_object *o)
{
	t_vector4f	u;
	t_vector4f	v;
	t_vector4f	u_d;
	t_vector4f	v_d;

	u = vector_normalize(vector_cross(o->direction, new_vector(0, 0, 1)));
	v = vector_normalize(vector_cross(u, o->direction));
	u_d = vector_projection(o->origin, u, r->pos);
	v_d = vector_projection(o->origin, v, r->pos);
	if (vector_dist(u_d, o->origin) <= o->radius / 2.0 && vector_dist(v_d, o->origin)
		<= o->radius / 2.0)
		return (find_plane_inter(r, o));
	return (MAX_SIZE);
}
