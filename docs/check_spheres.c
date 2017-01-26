/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:12:11 by telain            #+#    #+#             */
/*   Updated: 2017/01/24 22:45:36 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		check_spheres(t_env *e)
{
	t_sphere	*tmp;
	float		dist;

	tmp = e->objects->sphere->next;
	while (tmp)
	{
		if ((dist = check_sphere_inter(e, tmp)) < e->closest && dist >= 0.1)
		{
			e->closest = dist;
			e->hit = (void*)tmp;
		}
		tmp = tmp->next;
	}
}

float		check_sphere_inter(t_env *e, t_sphere *tmp)
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	res[3];

	a = sq(e->ray_v.x) + sq(e->ray_v.y) + sq(e->ray_v.z);
	b = 2 * (e->ray_v.x * (e->ray_s.x - tmp->s.x) +
			e->ray_v.y * (e->ray_s.y - tmp->s.y) +
			e->ray_v.z * (e->ray_s.z - tmp->s.z));
	c = sq(e->ray_s.x - tmp->s.x) + sq(e->ray_s.y - tmp->s.y) +
		sq(e->ray_s.z - tmp->s.z) - sq(tmp->size);
	d = sq(b) - 4 * a * c;
	if (d < 0)
		return (MAX_SIZE);
	res[0] = (-b - sqrt(d)) / (a + a);
	res[1] = (-b + sqrt(d)) / (a + a);
	res[2] = res[0] < res[1] ? res[0] : res[1];
	return (res[2]);
}
