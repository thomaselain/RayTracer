/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:37:37 by telain            #+#    #+#             */
/*   Updated: 2017/02/06 18:01:35 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_circle_inter(t_ray *r, t_object *o)
{
	float	d;

	d = find_plane_inter(r, o);
	return (vector_dist(o->origin, ADD(r->pos, MUL(r->dir, d))) < 3 ?
				d : MAX_SIZE);
}