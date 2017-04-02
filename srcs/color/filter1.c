/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:15:34 by cchicote          #+#    #+#             */
/*   Updated: 2017/04/02 18:14:09 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <math.h>

void				get_argb_comp(unsigned int c, int argb[4])
{
	argb[0] = (c >> 24) & 0xff;
	argb[1] = (c >> 16) & 0xff;
	argb[2] = (c >> 8) & 0xff;
	argb[3] = c & 0xff;
}

unsigned int		get_sepia(unsigned int c, int argb[4])
{
	int 			tr;
	int				tg;
	int				tb;
	int				avg;

	get_argb_comp(c, argb);
	avg = (argb[1] + argb[2] + argb[3]) / 3;
	tr = 1.5 * avg;
	tg = 1 * avg;
	tb = 0.5 * avg;
	argb[1] = (tr > 255 ? 255 : tr);
	argb[2] = (tg > 255 ? 255 : tg);
	argb[3] = (tb > 255 ? 255 : tb);
	c = (argb[1] << 16) | (argb[2] << 8) | argb[3];
	return (c);
}

unsigned int		get_black_white(unsigned int c, int argb[4])
{
	int				avg;

	get_argb_comp(c, argb);
	avg = (argb[1] + argb[2] + argb[3]) / 3;
	c = (avg << 16) | (avg << 8) | avg;
	return (c);
}

unsigned int		get_negative(unsigned int c, int argb[4])
{
	int				r;
	int				g;
	int				b;

	get_argb_comp(c, argb);
	r = 255 - argb[1];
	g = 255 - argb[2];
	b = 255 - argb[3];
	c = (r << 16) | (g << 8) | b;
	return (c);
}

unsigned int		get_one_color(unsigned int c, int argb[4], t_filter_type filter)
{
	int				r;
	int				g;
	int				b;

	r = 0;
	g = 0;
	b = 0;
	get_argb_comp(c, argb);
	if (filter == RED_FILTER)
		r = argb[1];
	else if (filter == GREEN_FILTER)
		g = argb[2];
	else if (filter == BLUE_FILTER)
		b = argb[3];
	c = (r << 16) | (g << 8) | b;
	return (c);
}
