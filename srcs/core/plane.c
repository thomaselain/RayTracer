/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:16:21 by svassal           #+#    #+#             */
/*   Updated: 2017/03/07 17:57:28 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

float		find_plane_inter(t_ray *r, t_object *o)
{
	return (-((o->direction.x * (r->pos.x - o->origin.x) + o->direction.y *
		(r->pos.y - o->origin.y) + o->direction.z * (r->pos.z -
			o->origin.z)) / (o->direction.x * r->dir.x + o->direction.y *
				r->dir.y + o->direction.z * r->dir.z)));
}
