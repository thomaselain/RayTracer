/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:13:49 by telain            #+#    #+#             */
/*   Updated: 2017/01/13 22:04:47 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		check_planes(t_env *e)
{
	t_plane		*tmp;
	float		dist;

	tmp = e->objects->plane->next;
	while (tmp)
	{
		if ((dist = check_plane_inter(e, tmp)) < e->closest && dist >= 0.1)
		{
			e->closest = dist;
			e->hit = (void*)tmp;
		}
		tmp = tmp->next;
	}
}

float		check_plane_inter(t_env *e, t_plane *tmp)
{	
	return (-((tmp->v.x * (e->ray_s.x - tmp->s.x) +
					tmp->v.y * (e->ray_s.y - tmp->s.y) +
					tmp->v.z * (e->ray_s.z - tmp->s.z)) /
				(tmp->v.x * e->ray_v.x +
				 tmp->v.y * e->ray_v.y +
				 tmp->v.z * e->ray_v.z)));
}
