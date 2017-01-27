/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 15:59:09 by fvivaudo          #+#    #+#             */
/*   Updated: 2017/01/26 18:38:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parser.h>
#include <win.h>
#include <img.h>
#include <thread.h>

void	get_camera_plane(t_scene *scene);

/*
static void		print_content(t_scene *s)
{
<<<<<<< HEAD
<<<<<<< HEAD
	t_object	obj;

	obj = s->objects;
=======
=======
>>>>>>> master
	t_list	*obj;
	t_list	*light;

	obj = s->objects;
	light = s->lights;
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
	printf("SCENE :\n");
	printf("\tCAMERA :\n");
	printf("\t\tORIGIN\n\t\t\t[X = %f ; Y = %f ; Z = %f]\n", s->camera.origin.x, s->camera.origin.y, s->camera.origin.z);
	printf("\t\tDIRECTION\n\t\t\t[X = %f ; Y = %f ; Z = %f]\n", s->camera.direction.x, s->camera.direction.y, s->camera.direction.z);
	printf("\t\tFOV = %d\n", s->camera.fov);
	printf("\tOBJECTS :\n");
	while (obj != 0)
	{
		printf("\t\tTYPE = %d\n", ((t_object *)s->objects->content)->type);
		printf("\t\t\tORIGIN\n\t\t\t\t[X = %f ; Y = %f ; Z = %f]\n", ((t_object *)s->objects->content)->origin.x, ((t_object *)s->objects->content)->origin.y, ((t_object *)s->objects->content)->origin.z);
		printf("\t\t\tDIRECTION\n\t\t\t\t[X = %f ; Y = %f ; Z = %f]\n", ((t_object *)s->objects->content)->direction.x, ((t_object *)s->objects->content)->direction.y, ((t_object *)s->objects->content)->direction.z);
		printf("\t\t\tCOLOR = %x\n", ((t_object *)s->objects->content)->color);
		printf("\t\t\tRADIUS = %f\n", ((t_object *)s->objects->content)->intensity);
		printf("\t\t\tREFLECTION = %f\n", ((t_object *)s->objects->content)->reflection);
		printf("\t\t\tDIFFUSE = %f\n", ((t_object *)s->objects->content)->diffuse);
		printf("\t\t\tCOMMENT = %s\n", ((t_object *)s->objects->content)->comment);
		obj = obj->next;
	}
	printf("\tLIGHTS :\n");
	while (light != 0)
	{
		printf("\t\tTYPE = %d\n", ((t_object *)s->lights->content)->type);
		printf("\t\t\tORIGIN\n\t\t\t\t[X = %f ; Y = %f ; Z = %f]\n", ((t_object *)s->lights->content)->origin.x, ((t_object *)s->lights->content)->origin.y, ((t_object *)s->lights->content)->origin.z);
		printf("\t\t\tDIRECTION\n\t\t\t\t[X = %f ; Y = %f ; Z = %f]\n", ((t_object *)s->lights->content)->direction.x, ((t_object *)s->lights->content)->direction.y, ((t_object *)s->lights->content)->direction.z);
		printf("\t\t\tCOLOR = %x\n", ((t_object *)s->lights->content)->color);
		printf("\t\t\tINTENSITY = %f\n", ((t_object *)s->lights->content)->intensity);
		printf("\t\t\tREFLECTION = %f\n", ((t_object *)s->lights->content)->reflection);
		printf("\t\t\tDIFFUSE = %f\n", ((t_object *)s->lights->content)->diffuse);
		printf("\t\t\tCOMMENT = %s\n", ((t_object *)s->lights->content)->comment);
		light = light->next;
	}
}
*/
__attribute__((weak)) int				main(int ac, char **av)
{
	t_win		win;
	t_img		img;
	t_scene		*e;
	int			status;
	t_tcore		**core;
	float		loading;
	t_img		image;

	status = 0;
	//Load and parse config
	if (ac == 2)
	{
		e = scene_parse_file(av[1]);
	//	print_content(e);
	}else{
		return (0);
	}
	//Load window
	win_init(&win, "RT", WIDTH, HEIGHT);
	img_init(&img, WIDTH, HEIGHT, 0x0);
	win_draw_center(&win, &img);
	get_camera_plane(e);         // Calcule les vecteurs up et right de la camera avant les lancers de rayon


	//TODO interface

	img_init(&image, 410, 60, 0x5555555);
	win_draw_center(&win, &image);
	img_destroy(&image);
	win_render(&win);

	//Core calculation and display
	const int nbthread = 4;
	core = thread_init(e, &img, nbthread);
	loading = 0;
	//Event management
	status = 0;
	SDL_Event event;
	SDL_KeyboardEvent *key = 0;
	while (status == 0 && loading >= 0 && loading < 1.0) {
		printf("%2.0f %%\r", loading * 100.0);
		win_draw_center(&win, &img);
		img_init(&image, 410, 60, 0x5555555);
		win_draw_center(&win, &image);
		img_destroy(&image);
		img_init(&image, loading * 400, 50, 0xffffff);
		win_draw_center(&win, &image);
		img_destroy(&image);
		win_render(&win);
		loading = thread_status(core, nbthread);


		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_KEYDOWN:
			key = &event.key;
			printf("Key press detected %d \n", key->keysym.scancode);
			break;
		case SDL_KEYUP:
			key = &event.key;
			if (key->keysym.scancode == 41)
				status = 2;
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
	win_render(&win);

	thread_end(core, nbthread);

	img_save(&img, "capture.bmp");

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
				if (key->keysym.scancode == 41)
					status = 2;
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
	scene_destroy(e);
	img_destroy(&img);
	win_destroy(&win);
	return (0);
}
