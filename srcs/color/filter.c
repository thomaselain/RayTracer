/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:15:34 by cchicote          #+#    #+#             */
/*   Updated: 2017/02/16 18:55:42 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <math.h>

int					*get_argb_comp(unsigned int c, int argb[4])
{
	argb[0] = (c >> 24) & 0xff;
	argb[1] = (c >> 16) & 0xff;
	argb[2] = (c >> 8) & 0xff;
	argb[3] = c & 0xff;
	return (argb);
}

unsigned int		get_sepia(unsigned int c, int argb[4])
{
	int 			tr;
	int				tg;
	int				tb;

	argb = get_argb_comp(c, argb);
	tr = (int)(0.393 * argb[1] + 0.769 * argb[2] + 0.189 * argb[3]);
	tg = (int)(0.349 * argb[1] + 0.686 * argb[2] + 0.168 * argb[3]);
	tb = (int)(0.272 * argb[1] + 0.534 * argb[2] + 0.131 * argb[3]);
	argb[1] = (tr > 255 ? 255 : tr);
	argb[2] = (tg > 255 ? 255 : tg);
	argb[3] = (tb > 255 ? 255 : tb);
	c = (argb[1] << 16) | (argb[2] << 8) | argb[3];
	return (c);
}

unsigned int		get_black_white(unsigned int c, int argb[4])
{
	int				avg;

	argb = get_argb_comp(c, argb);
	avg = (argb[1] + argb[2] + argb[3]) / 3;
	c = (avg << 16) | (avg << 8) | avg;
	return (c);
}

unsigned int		get_negative(unsigned int c, int argb[4])
{
	int				r;
	int				g;
	int				b;

	argb = get_argb_comp(c, argb);
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

	argb = get_argb_comp(c, argb);
	if (filter == RED_FILTER)
	{
		r = argb[1];
		g = 0;
		b = 0;
	}
	else if (filter == GREEN_FILTER)
	{
		r = 0;
		g = argb[2];
		b = 0;
	}
	else if (filter == BLUE_FILTER)
	{
		r = 0;
		g = 0;
		b = argb[3];
	}
	c = (r << 16) | (g << 8) | b;
	return (c);
}

unsigned int		add_filter(unsigned int c, t_filter_type filter)
{
	int				argb[4];

	if (filter == NEGATIVE)
		c = get_negative(c, argb);
	else if (filter == BLACK_WHITE)
		c = get_black_white(c, argb);
	else if (filter == SEPIA)
		c = get_sepia(c, argb);
	else if (filter == RED_FILTER || filter == GREEN_FILTER || filter == BLUE_FILTER)
		c = get_one_color(c, argb, filter);
	return (c);
}
