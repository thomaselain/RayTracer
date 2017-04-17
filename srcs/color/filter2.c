/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:13:15 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 18:14:06 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <math.h>

unsigned int		add_filter(unsigned int c, t_filter_type filter)
{
	int				argb[4];

	if (filter == NEGATIVE)
		c = get_negative(c, argb);
	else if (filter == BLACK_WHITE)
		c = get_black_white(c, argb);
	else if (filter == SEPIA)
		c = get_sepia(c, argb);
	else if (filter == RED_FILTER || filter == GREEN_FILTER ||
		filter == BLUE_FILTER)
		c = get_one_color(c, argb, filter);
	return (c);
}