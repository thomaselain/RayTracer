/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:13:51 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/26 18:13:55 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <win.h>

void		win_draw(t_win *win, t_img *img, int x, int y)
{
	SDL_Texture	*tex;
	SDL_Rect	dst;

	tex = SDL_CreateTextureFromSurface(win->rdr, img->srf);
	if (tex != 0)
	{
		SDL_QueryTexture(tex, 0, 0, &dst.w, &dst.h);
		dst.x = x;
		dst.y = y;
		SDL_RenderCopy(win->rdr, tex, NULL, &dst);
		SDL_DestroyTexture(tex);
	}
}

void		win_draw_center(t_win *win, t_img *img)
{
	win_draw(win, img, (win->w - img->w) / 2, (win->h - img->h) / 2);
}
