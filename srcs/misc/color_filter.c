/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:00:58 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 18:15:24 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A(x)		((x & 0xff000000) >> 24)
#define R(x)		((x & 0xff0000) >> 16)
#define G(x)		((x & 0xff00) >> 8)
#define B(x)		((x & 0xff))
#define ROUND(x)	((x + 0.5 >= (int)x + 1) ? ((int)x + 1) : ((int)x))
#define SEPIA		1
#define BLACK_WHITE	2

/*
** Return the input color converted to the given color filter
*/

static unsigned int	sepia_filter(unsigned int in_color)
{
	unsigned int	ret;
	unsigned short	tmp;

	ret = 0xff;
	ret <<= 8;
	tmp = ROUND((float)(R(in_color) * 0.393f) + (float)(G(in_color) *
		0.769f) + (float)(B(in_color) * 0.189f));
	ret += ((tmp > 255) ? (255) : (tmp));
	ret <<= 8;
	tmp = ROUND((float)(R(in_color) * 0.349f) + (float)(G(in_color) *
		0.686f) + (float)(B(in_color) * 0.168f));
	ret += ((tmp > 255) ? (255) : (tmp));
	ret <<= 8;
	tmp = ROUND((float)(R(in_color) * 0.272f) + (float)(G(in_color) *
		0.534f) + (float)(B(in_color) * 0.131f));
	ret += ((tmp > 255) ? (255) : (tmp));
	return (ret);
}

static unsigned int	bw_filter(unsigned int in_color)
{
	unsigned int ret;
	unsigned int tmp;

	tmp = ROUND((R(in_color) + G(in_color) + B(in_color)) / 3);
	ret = 0xff;
	ret <<= 8;
	ret += tmp;
	ret <<= 8;
	ret += tmp;
	ret <<= 8;
	ret += tmp;
	return (ret);
}

unsigned int		color_filter(unsigned int in_color, int type)
{
	if (type == SEPIA)
		return (sepia_filter(in_color));
	else if (type == BLACK_WHITE)
		return (bw_filter(in_color));
	return (in_color);
}
