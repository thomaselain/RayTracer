/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:18:19 by telain            #+#    #+#             */
/*   Updated: 2017/04/02 18:00:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

t_vector4f	get_normal(t_object *o, t_ray ray)
{
	t_vector4f	n;

	n = ((t_vector4f){0.0, 0.0, 0.0, 1.0});
	if (o->type == SPHERE)
		n = sphere_normal(o, ray);
	else if (o->type == PLANE || o->type == CIRCLE ||
		o->type == RECTANGLE || o->type == TRIANGLE)
	{
		n = vector_normalize(o->direction);
		if (vector_dot(n, ray.dir) > 0)
			n = MUL(n, -1);
	}
	else if (o->type == CYLINDER)
		n = cylinder_normal(o, ray);
	else if (o->type == CONE)
		n = cone_normal(o, ray);
	return (n); //Bump mapping ? :/
}
