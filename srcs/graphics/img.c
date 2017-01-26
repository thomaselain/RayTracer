/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:47:25 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/03 18:50:10 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img.h>

static SDL_Color	translate_color(int argb_color)
{
	SDL_Color color;

	color.a = (argb_color & 0xff000000) >> 24;
	color.r = (argb_color & 0xff0000) >> 16;
	color.g = (argb_color & 0xff00) >> 8;
	color.b = (argb_color & 0xff);
	return (color);
}

int					img_init(t_img *img, int width, int height,
							unsigned int argb_color)
{
	SDL_Rect	dst;

	img->srf = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	if (img->srf)
	{
		img->w = img->srf->w;
		img->h = img->srf->h;
		dst.x = 0;
		dst.y = 0;
		dst.w = img->w;
		dst.h = img->h;
		SDL_FillRect(img->srf, &dst, argb_color);
		return (1);
	}
	img_destroy(img);
	return (0);
}

int					img_init_text(t_img *img, const char *text,
						unsigned int argb_color, int fontsize)
{
	TTF_Font *font;

	font = TTF_OpenFont("res/arial.ttf", fontsize);
	if (font != 0)
	{
		img->srf = TTF_RenderText_Solid(font, text,
			translate_color(argb_color));
		TTF_CloseFont(font);
		if (img->srf)
		{
			img->w = img->srf->w;
			img->h = img->srf->h;
			return (1);
		}
	}
	img_destroy(img);
	return (0);
}

int					img_init_bmp(t_img *img, const char *file)
{
	img->srf = SDL_LoadBMP(file);
	if (img->srf)
	{
		img->w = img->srf->w;
		img->h = img->srf->h;
		return (1);
	}
	img_destroy(img);
	return (0);
}

int					img_save(t_img *img, const char *filename)
{
	if (SDL_SaveBMP(img->srf, filename) == 0)
	{
		return (1);
	}
	return (0);
}

void				img_destroy(t_img *img)
{
	SDL_FreeSurface(img->srf);
	img->srf = 0;
	img->w = 0;
	img->h = 0;
}
