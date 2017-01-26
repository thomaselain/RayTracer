/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:26:43 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/03 18:07:10 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
# define WIN_H
# include "img.h"

typedef struct		s_win
{
	SDL_Window		*wdw;
	SDL_Renderer	*rdr;
	int				w;
	int				h;
}					t_win;

int					win_init(t_win *win, char *title, int width, int height);
void				win_destroy(t_win *win);
void				win_draw(t_win *win, t_img *img, int x, int y);
void				win_draw_center(t_win *win, t_img *img);
void				win_render(t_win *win);

#endif
