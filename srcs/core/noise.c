/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:48:32 by telain            #+#    #+#             */
/*   Updated: 2017/02/12 14:58:16 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		noise(t_object *o, t_vector4f pos)
{
	if (o->noise.type == PERLIN)
		return (perlin(pos.x / 10, pos.y / 10, pos.z / 10));
	return (1);
}
