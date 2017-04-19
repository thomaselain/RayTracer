/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:05:53 by telain            #+#    #+#             */
/*   Updated: 2017/04/19 17:04:31 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <core.h>

/*
**	Returns c1 + c2 in a new unsigned int as a color
*/
unsigned int		color_add(unsigned int c1, unsigned int c2);

/*
**	Returns c1 - c2 in a new unsigned int as a color
*/

unsigned int		color_sub(unsigned int c1, unsigned int c2);

/*
**	Returns c1 * m in a new unsigned int as a color
*/

unsigned int		color_mul(unsigned int c, float m);

/*
**	Returns c1 / d in a new unsigned int as a color
*/

unsigned int		color_div(unsigned int c, float d);

/*
**	Returns the average of c1 and c2
*/

unsigned int		color_avg(unsigned int c1, unsigned int c2);

/*
** Returns the color of the scene after the application of a sepia filter
*/

unsigned int		get_sepia(unsigned int c, int argb[4]);

/*
** Returns the color of the scene after the application of a black and white
** filter
*/

unsigned int		get_black_white(unsigned int c, int argb[4]);

/*
** Returns the color of the scene after the application of a negative filter
*/

unsigned int		get_negative(unsigned int c, int argb[4]);

/*
** Returns the color of the scene after the application of a red
** or green or blue filter depending on the parameter file
*/

unsigned int		get_one_color(unsigned int c, int argb[4],
		t_filter_type filter);

/*
** Returns the filtered argb color at pixel (x, y);
*/

unsigned int		add_filter(unsigned int c, t_filter_type filter);

/*
** Isolates the ARGB components and place them into an int tab called argb
*/

void				get_argb_comp(unsigned int c, int argb[4]);

#endif
