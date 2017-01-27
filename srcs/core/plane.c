/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:16:21 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 15:40:22 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

/*
** Check if the ray intersects with the plane given as parameter
*/

float		find_plane_inter(t_ray *r, t_object *o)
{
	return (-((o->direction.x * (r->origin.x - o->origin.x) + o->direciton.y *
		(r->origin.y - o->origin.y) + o->direction.z * (r->origin.z -
			o->origin.z)) / (o->direction.x * r->direction.x + o->direction.y *
				r->direction.y + o->direction.z * r->direction.z)));
}
