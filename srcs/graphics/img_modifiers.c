/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:57:20 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/27 18:58:33 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img.h>
#define A(x)		((x & 0xff000000) >> 24)
#define R(x)		((x & 0xff0000) >> 16)
#define G(x)		((x & 0xff00) >> 8)
#define B(x)		((x & 0xff))
#define ROUND(x)	((x + 0.5 >= (int)x + 1) ? ((int)x + 1) : ((int)x))

/*
** Return the input color converted to the given color filter
*/

static unsigned int	color_filter(unsigned int input_color, unsigned int filter)
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

int					img_save(t_img *img, const char *filename)
{
	if (SDL_SaveBMP(img->srf, filename) == 0)
	{
		return (1);
	}
	return (0);
}

void				img_set_filter(t_img *img, unsigned int argb_filter)
{
	int		x;
	int		y;

	x = 0;
	while (img != 0 && img->srf != 0 && x < (img->w))
	{
		y = 0;
		while (y < (img->h))
		{
			img_set_pixel(img, x, y, color_filter(img_get_pixel(img, x, y),
				argb_filter));
			y++;
		}
		x++;
	}
}

unsigned int		img_get_pixel(t_img *img, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = img->srf->format->BytesPerPixel;
	p = (Uint8 *)img->srf->pixels + y * img->srf->pitch + x * bpp;
	if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3 && SDL_BYTEORDER == SDL_BIG_ENDIAN)
		return (p[0] << 16 | p[1] << 8 | p[2]);
	else if (bpp == 3)
		return (p[0] | p[1] << 8 | p[2] << 16);
	else if (bpp == 4)
		return (*(Uint32 *)p);
	return (*p);
}

void				img_set_pixel(t_img *img, int x, int y,
	unsigned int argb_color)
{
	int		bpp;
	Uint8	*p;

	bpp = img->srf->format->BytesPerPixel;
	p = (Uint8 *)img->srf->pixels + y * img->srf->pitch + x * bpp;
	if (bpp == 1)
		*p = argb_color;
	else if (bpp == 2)
		*(Uint16 *)p = argb_color;
	else if (bpp == 3 && SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		p[0] = (argb_color >> 16) & 0xff;
		p[1] = (argb_color >> 8) & 0xff;
		p[2] = argb_color & 0xff;
	}
	else if (bpp == 3)
	{
		p[0] = argb_color & 0xff;
		p[1] = (argb_color >> 8) & 0xff;
		p[2] = (argb_color >> 16) & 0xff;
	}
	else if (bpp == 4)
		*(Uint32 *)p = argb_color;
}
