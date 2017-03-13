/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:48:32 by telain            #+#    #+#             */
/*   Updated: 2017/03/07 17:56:30 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		noise(t_object *o, t_vector4f pos)
{
	float	ret;

	ret = 1;
	pos = DIV(pos, o->noise.zoom / 10);
	if (o->noise.material_type == PERLIN)
		ret = perlin(pos.x, pos.y, pos.z);
	else if (o->noise.material_type == GRID)
		ret = grid(pos, o->noise.zoom);
	ret = ret >= 1.0 ? 1.0 : ret;
	return (ret);
}
