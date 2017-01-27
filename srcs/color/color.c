/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:05:31 by telain            #+#    #+#             */
/*   Updated: 2017/01/28 00:44:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <math.h>

unsigned int	color_add(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = (c1 & 0xff0000) + (c2 & 0xff0000);
	r = r < 0xffff ? 0 : r;
	g = (c1 & 0xff00) + (c2 & 0xff00);
	g = g < 0xffff ? 0 : g;
	b = (c1 & 0xff) + (c2 & 0xff);
	b = b < 0xffff ? 0 : b;
	return (r + g + b);
}

unsigned int	color_sub(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = (c1 & 0xff0000) - (c2 & 0xff0000);
	r = r <= 0xffff ? 0 : r;
	g = (c1 & 0xff00) - (c2 & 0xff00);
	g = g <= 0xff ? 0 : g;
	b = (c1 & 0xff) - (c2 & 0xff);
	b = b <= 0 ? 0 : b;
	return (r + g + b);
}

unsigned int	color_mul(unsigned int c, float m)
{
	return (((int)((c & 0xff0000) * fabs(m)) & 0xff0000) +
			(((int)((c & 0xff00) * fabs(m)) & 0xff00) +
			 (((int)((c & 0xff) * fabs(m)) & 0xff))));
}

unsigned int	color_div(unsigned int c, float d)
{
	return (((c & 0xff0000) >> 16) / d +
			((c & 0xff00) >> 8) / d +
			(c & 0xff) / d);
}
