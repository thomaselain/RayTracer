/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:49:36 by telain            #+#    #+#             */
/*   Updated: 2017/02/06 22:29:24 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
# define BH v[0]
# define AXIS v[1]

t_vector4f		vector_projection(t_vector4f s, t_vector4f axis, t_vector4f p)
{
	t_vector4f	new;
	float		v[2];

	AXIS = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2));
	BH = ((p.x - s.x) * axis.x + (p.y - s.y) * axis.y + (p.z - s.z) * axis.z)
		/ AXIS;
	new.x = s.x + (BH / AXIS) * axis.x;
	new.y = s.y + (BH / AXIS) * axis.y;
	new.z = s.z + (BH / AXIS) * axis.z;
	return (new);
}
