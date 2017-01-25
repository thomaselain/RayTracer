/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:01:40 by aljourda          #+#    #+#             */
/*   Updated: 2017/01/03 18:08:11 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H
# include <SDL2/SDL.h>
# ifndef OS
#  include <SDL2_ttf/SDL_ttf.h>
# else
#  include <SDL2/SDL_ttf.h>
# endif

typedef struct		s_img
{
	SDL_Surface		*srf;
	int				w;
	int				h;
}					t_img;

int					img_init(t_img *img, int width, int height,
								unsigned int argb_color);
int					img_init_bmp(t_img *img, const char *file);
int					img_init_text(t_img *img, const char *text,
						unsigned int argb_color, int fontsize);
void				img_set_pixel(t_img *img, int x, int y,
								unsigned int argb_color);
void				img_destroy(t_img *img);

#endif
