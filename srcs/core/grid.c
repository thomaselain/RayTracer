/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:04:06 by telain            #+#    #+#             */
/*   Updated: 2017/04/02 18:00:36 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>

float		grid(t_vector4f pos, float size)
{
	if (sin(M_PI * pos.x + size) * cos(M_PI * pos.y + size) *
		sin(M_PI * pos.z + size) >= 0)
		return (1);
	return (0.5);
}
