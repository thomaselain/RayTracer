/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:57:20 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/12 14:57:40 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img.h>

void			img_set_pixel(t_img *img, int x, int y, unsigned int argb_color)
{
	Uint32 *pixels;

	if (img != 0 && x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		pixels = (Uint32 *)img->srf->pixels;
		*(pixels + y * img->w + x) = argb_color;
	}
}
