/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:27:40 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/03 19:00:10 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <win.h>

static int	sdl_init(int init)
{
	static int sdlinit;

	if (init == 1)
		sdlinit++;
	if (sdlinit == 1 && init == 1 && SDL_Init(SDL_INIT_VIDEO) != 0)
		init = 0;
	if (sdlinit == 1 && init == 1 && TTF_Init() != 0)
		init = 0;
	if (init == 0)
		sdlinit--;
	if (sdlinit == 0 && init == 0)
	{
		TTF_Quit();
		SDL_Quit();
	}
	return (init);
}

void		win_render(t_win *win)
{
	SDL_RenderPresent(win->rdr);
}

int			win_init(t_win *win, char *title, int width, int height)
{
	if (sdl_init(1) == 1)
	{
		win->w = width;
		win->h = height;
		win->wdw = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (win->wdw != 0)
		{
			win->rdr = SDL_CreateRenderer(win->wdw, -1,
				SDL_RENDERER_SOFTWARE);
			if (win->rdr != 0)
			{
				SDL_RenderPresent(win->rdr);
				return (1);
			}
		}
	}
	win_destroy(win);
	return (0);
}

void		win_destroy(t_win *win)
{
	SDL_DestroyRenderer(win->rdr);
	SDL_DestroyWindow(win->wdw);
	win->rdr = 0;
	win->wdw = 0;
	win->w = 0;
	win->h = 0;
	sdl_init(0);
}
