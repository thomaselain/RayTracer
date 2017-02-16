/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modifications_recursive.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:42:04 by telain            #+#    #+#             */
/*   Updated: 2017/02/16 18:48:58 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <img.h>
#include <color.h>


int		adjust_color(t_scene *s, t_object *hit, t_ray ray, int reflects)
{
	if (hit != 0 && hit->reflection > 0.0 && reflects <= MAX_REFLECTION)
	{
		return (color_mul(hit->reflection, adjust_color(s, get_reflect(s, hit, &ray), ray, reflects + 1));
	}
}
