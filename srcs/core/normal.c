/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:18:19 by telain            #+#    #+#             */
/*   Updated: 2017/01/27 23:48:42 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

t_vector4f	get_normal(t_object *o, t_ray ray)
{
	if (o->type == SPHERE)
		return (sphere_normal(o, ray));
	else if (o->type == PLANE)
		return (vector_normalize(o->direction));
	return ((t_vector4f){0.0, 0.0, 0.0, 0.0});
}
