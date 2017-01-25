/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 15:59:09 by fvivaudo          #+#    #+#             */
/*   Updated: 2016/11/25 18:04:42 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <win.h>
#include <img.h>
#include <thread.h>


__attribute__((weak)) unsigned int ray_pixel(t_scene *scene, int x, int y){

	return (0xffffffff);
}

int				main(int ac, char **av)
{
	t_win		win;
	t_img		img;
	t_scene		*e;
	int			fd;
	int			status;
	t_tcore		**core;
	float		loading;
	t_img		image;

	status = 0;
	//Load and parse config
/*	if (ac != 2 || (fd = open(av[1], O_RDONLY)) <= -1 || !(e = readConfig(fd)))
	{
		//error message?
		return (0);
	}
*/	//Load window
	win_init(&win, "RT", WIDTH, HEIGHT);
	img_init(&img, WIDTH, HEIGHT, 0x0);
	win_draw_center(&win, &img);



	//TODO interface

	img_init(&image, 410, 60, 0x5555555);
	win_draw_center(&win, &image);
	img_destroy(&image);

	//Core calculation and display
	const int nbthread = 40;
	core = thread_init(e, &img, nbthread);
	loading = 0;
	//Event management
	status = 0;
	SDL_Event event;
	SDL_KeyboardEvent *key = 0;
	while (status == 0 && loading >= 0 &&loading < 1.0) {
		printf("%2.0f %%\r", loading * 100.0);
		img_init(&image, loading * 400, 50, 0xffffff);
		win_draw_center(&win, &image);
		img_destroy(&image);
		loading = thread_status(core, nbthread);


		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_KEYDOWN:
			key = &event.key;
			printf("Key press detected %d \n", key->keysym.scancode);
			break;
		case SDL_KEYUP:
			key = &event.key;
			printf("Key release detected %d \n", key->keysym.scancode);
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_WINDOWEVENT_CLOSE:
		case SDL_QUIT:
			status = 1;
			break;
		default:
//				printf("event : %d\r\n", event.type);
			break;
		}
	}
	printf("100 %%\n");
	win_draw_center(&win, &img);
	thread_end(core, nbthread);


	status = 0;
	//Event management
	while (status == 0) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				key = &event.key;
				printf("Key press detected %d \n", key->keysym.scancode);
				break;
			case SDL_KEYUP:
				key = &event.key;
				printf("Key release detected %d \n", key->keysym.scancode);
				break;
			case SDL_MOUSEMOTION:
				break;
			case SDL_WINDOWEVENT_CLOSE:
			case SDL_QUIT:
				status = 1;
				break;
			default:
//				printf("event : %d\r\n", event.type);
				break;
			}
		}
	}
	img_destroy(&img);
	win_destroy(&win);
	return (0);
}
