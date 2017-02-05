/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:25:08 by telain            #+#    #+#             */
/*   Updated: 2017/02/05 16:48:39 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vector_dist(t_vector4f v1, t_vector4f v2)
{
	return (sqrt(pow(v1.x - v2.x, 2)
				+ pow(v1.y - v2.y, 2)
				+ pow(v1.z - v2.z, 2)));
}
