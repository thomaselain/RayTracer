/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:23:14 by telain            #+#    #+#             */
/*   Updated: 2017/01/13 22:25:31 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		check_cylinders(t_env *e)
{
	t_cylinder		*tmp;
	float		dist;

	tmp = e->objects->cylinder->next;
	while (tmp)
	{
		if ((dist = check_cylinder_inter(e, tmp)) < e->closest && dist >= 0.1)
		{
			e->closest = dist;
			e->hit = (void*)tmp;
		}
		tmp = tmp->next;
	}
}

float		check_cylinder_inter(t_env *e, t_cylinder *tmp)
{
	float	res[7];

	res[3] = v_dot(e->ray_v, e->ray_v) - sq(v_dot(tmp->v, e->ray_v));
		res[4] = 2 * (v_dot(e->ray_v, v_sub(e->ray_s, tmp->s)) - v_dot(e->ray_v,
									tmp->v) * v_dot(v_sub(e->ray_s, tmp->s), tmp->v));
			res[5] = v_dot(v_sub(e->ray_s, tmp->s), v_sub(e->ray_s, tmp->s))
						- sq(v_dot(v_sub(e->ray_s, tmp->s), tmp->v)) - sq(tmp->size);
	res[6] = sq(res[4]) - 4 * res[3] * res[5];
	if (res[6] < 0)
		return (MAX_SIZE);
	res[0] = (-res[4] - sqrt(res[6])) / (res[3] + res[3]);
	res[1] = (-res[4] + sqrt(res[6])) / (res[3] + res[3]);
	res[2] = res[0] < res[1] ? res[0] : res[1];
	return (res[2]);
}
