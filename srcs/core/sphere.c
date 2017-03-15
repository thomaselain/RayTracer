/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:16:37 by telain            #+#    #+#             */
/*   Updated: 2017/03/15 15:22:48 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A		(val[0])
#define B		(val[1])
#define C		(val[2])
#define D		(val[3])
#define X1		(val[5])
#define X2		(val[6])
#define RET		(val[4])
#include <core.h>
#include <ray.h>

float		find_sphere_inter(t_ray *ray, t_object *obj)
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
		return (MAX_SIZE);
	X1 = (-B - sqrt(D)) / (A + A);
	X2 = (-B + sqrt(D)) / (A + A);
	return (X1 < X2 ? X1 : X2);
}

t_vector4f	sphere_normal(t_object *o, t_ray ray)
{
	return (vector_normalize(SUB(ray.pos, o->origin)));
}
