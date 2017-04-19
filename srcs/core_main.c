/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/31 15:59:09 by aljourda          #+#    #+#             */
/*   Updated: 2017/04/05 18:53:45 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parser.h>
#include <win.h>
#include <img.h>
#include <thread.h>
#include <ray.h>
#include <events.h>

static int		progress(t_win *win, t_img *img, t_tcore **tc, int nbthd)
{
	float				loading;
	int					status;
	t_img				image;

	loading = 0;
	status = 0;
	while (status == 0 && loading >= 0 && loading < 1.0)
	{
		win_draw_center(win, img);
		img_init(&image, 410, 60, 0x5555555);
		win_draw_center(win, &image);
		img_destroy(&image);
		img_init(&image, loading * 400, 50, 0xffffff);
		win_draw_center(win, &image);
		img_destroy(&image);
		win_render(win);
		loading = thread_status(tc, nbthd);
		status = key_status_progress();
	}
	return (status);
}

static int		calculation(t_scene *e, t_win *win, int nbthd)
{
	t_img		img;
	t_tcore		**tc;
	int			status;

	img_init(&img, WIDTH, HEIGHT, 0x0);
	tc = thread_init(e, &img, nbthd);
	status = progress(win, &img, tc, nbthd);
	win_draw_center(win, &img);
	win_render(win);
	thread_end(tc, nbthd);
	img_save(&img, "capture.bmp");
	img_destroy(&img);
	return (status);
}

static void		main_loop(t_scene *e, t_win *win, int nbthd)
{
	int			status;

	status = 3;
	while (status > 2)
	{
		if (status == 3)
		{
			get_camera_plane(e);
			status = calculation(e, win, nbthd);
			if (status == 1 || status == 2)
				continue ;
		}
		status = 0;
		while (status == 0)
		{
			status = key_status_loop(e);
		}
	}
}

int				main(int ac, char **av)
{
	t_win		win;
	t_scene		*e;
	int			nbthd;

	if (ac >= 2)
	{
		nbthd = 20;
		e = scene_parse_file(av[1]);
		win_init(&win, "RT", WIDTH, HEIGHT);
		main_loop(e, &win, nbthd);
		scene_destroy(e);
		win_destroy(&win);
		return (0);
	}
	ft_putstr("usage : ./RT filename\n");
	return (0);
}
