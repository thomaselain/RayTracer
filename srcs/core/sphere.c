/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:16:37 by telain            #+#    #+#             */
/*   Updated: 2017/01/26 21:29:07 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		find_sphere_inter(t_scene *s, t_ray *ray, t_object *obj)
{
	float	val[7];

	A = pow(ray->dir.x, 2) + pow(ray->dir.y, 2) + pow(ray->dir.z, 2);
	B = 2 * (ray->dir.x * (ray->pos.x - obj->origin.x) +
			ray->dir.y * (ray->pos.y - obj->origin.y) +
			ray->dir.z * (ray->pos.z - obj->origin.z));
	C = pow(ray->pos.x - obj->origin.x, 2) + pow(ray->pos.y - obj->origin.y, 2)
		+ pow(ray->pos.z - obj->origin.z, 2) - pow(obj->radius, 2);
	D = pow(B, 2) - (4 * A * C);
	if (D < 0)
		return (100000.0);
	X1 = (-B - sqrt(D)) / (A + A);
	X2 = (-B + sqrt(D)) / (A + A);
	return (X1 < X2 ? X1 : X2);
}
