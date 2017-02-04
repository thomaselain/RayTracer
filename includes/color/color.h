/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:05:53 by telain            #+#    #+#             */
/*   Updated: 2017/02/04 16:15:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

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

#endif
