/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:13:49 by telain            #+#    #+#             */
/*   Updated: 2017/01/24 22:14:27 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		check_cones(t_env *e)
{
	t_cone		*tmp;
	float		dist;

	tmp = e->objects->cone->next;
	while (tmp)
	{
		if ((dist = check_cone_inter(e, tmp)) < e->closest && dist >= 0.1)
		{
			e->closest = dist;
			e->hit = (void*)tmp;
		}
		tmp = tmp->next;
	}
}

float		check_cone_inter(t_env *e, t_cone *tmp)
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	res[2];

	a = v_dot(e->ray_v, e->ray_v) - sq(v_dot(e->ray_v, tmp->v)) *
		(1 + sq(tan(tmp->angle / 2)));
	b = 2 * ((v_dot(e->ray_v, v_sub(e->ray_s, tmp->s))) -
			(1 + sq(tan(tmp->angle / 2))) * v_dot(e->ray_v, tmp->v) *
			v_dot(v_sub(e->ray_s, tmp->s), tmp->v));
	c = v_dot(v_sub(e->ray_s, tmp->s), v_sub(e->ray_s, tmp->s)) -
		(1 + sq(tan(tmp->angle / 2))) * sq(v_dot(v_sub(e->ray_s, tmp->s),
					tmp->v));
	d = sq(b) - 4 * a * c;
	if (tmp)
		;
	if (d < 0)
		return (MAX_SIZE);
	res[0] = (-b - sqrt(d)) / (a + a);
	res[1] = (-b + sqrt(d)) / (a + a);
	return (res[0] < res[1] ? res[0] : res[1]);
}
