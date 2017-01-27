/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:00:58 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 15:01:07 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A(x)		((x & 0xff000000) >> 24)
#define R(x)		((x & 0xff0000) >> 16)
#define G(x)		((x & 0xff00) >> 8)
#define B(x)		((x & 0xff))
#define ROUND(x)	((x + 0.5 >= (int)x + 1) ? ((int)x + 1) : ((int)x))
#define SEPIA		0xff704214

unsigned int	color_filter(unsigned int input_color, unsigned int filter)
{
	unsigned int	ret;
	unsigned char	c;

	c = A(input_color);
	ret = c;
	ret <<= 8;
	c = R(input_color);
	c = ROUND((float)(((float)c / 255.0f) * (float)R(filter)));
	ret += c;
	ret <<= 8;
	c = G(input_color);
	c = ROUND((float)(((float)c / 255.0f) * (float)G(filter)));
	ret += c;
	ret <<= 8;
	c = B(input_color);
	c = ROUND((float)(((float)c / 255.0f) * (float)B(filter)));
	ret += c;
	return (ret);
}
