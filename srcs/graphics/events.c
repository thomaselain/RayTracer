/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:43:56 by aljourda          #+#    #+#             */
/*   Updated: 2017/04/19 17:44:13 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <core.h>
#include <parser.h>
#include <win.h>
#include <img.h>
#include <thread.h>
#include <ray.h>

int		key_status_progress(void)
{
	int					status;
	SDL_Event			event;
	SDL_KeyboardEvent	*key;

	status = 0;
	key = 0;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		key = &event.key;
		status = 3;
	}
	else if (event.type == SDL_WINDOWEVENT_CLOSE || event.type == SDL_QUIT)
	{
		status = 1;
	}
	return (status);
}

int		key_status_loop(t_scene *e)
{
	int					status;
	SDL_Event			event;
	SDL_KeyboardEvent	*key;

	status = 0;
	key = 0;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			key = &event.key;
			break;
		case SDL_KEYUP:
			key = &event.key;
			if (key->keysym.scancode == 41)
				status = 2;
			else if (key->keysym.scancode >= 79 && key->keysym.scancode <= 82)
			{	
				if (key->keysym.scancode == 82)
					e->camera.origin = ADD(e->camera.origin, MUL(e->camera.direction, 2));;
				if (key->keysym.scancode == 81)
					e->camera.origin = SUB(e->camera.origin, MUL(e->camera.direction, 2));;
				if (key->keysym.scancode == 80)
					e->camera.origin = ADD(e->camera.origin,
							vector_cross(e->camera.direction, (t_vector4f){0.0, 0.0, 1.0, 0.0}));
				if (key->keysym.scancode == 79)
					e->camera.origin = SUB(e->camera.origin,
							vector_cross(e->camera.direction, (t_vector4f){0.0, 0.0, 1.0, 0.0}));
				status = 3;
			}
			else if (key->keysym.scancode >= 86 && key->keysym.scancode <= 87)
			{
				if (key->keysym.scancode == 87)
					e->camera.origin.z += 0.6;
				if (key->keysym.scancode == 86)
					e->camera.origin.z -= 0.6;
				status = 3;
			}
			else
			{
				if (key->keysym.scancode == 92)
				{
					e->camera.direction.x += e->camera.direction.x *
						cos(-M_PI / 6) - e->camera.direction.y * sin(-M_PI / 6);
					e->camera.direction.y += e->camera.direction.x *
						sin(-M_PI / 6) + e->camera.direction.y * cos(-M_PI / 6);
					e->camera.direction = vector_normalize(e->camera.direction);
				}
				if (key->keysym.scancode == 96)
				{
					e->camera.direction.z += e->camera.direction.z *
						cos(M_PI / 6) - e->camera.direction.y * sin(M_PI / 6);
					e->camera.direction.y += e->camera.direction.z *
						sin(M_PI / 6) + e->camera.direction.y * cos(M_PI / 6);
					e->camera.direction = vector_normalize(e->camera.direction);
				}
				if (key->keysym.scancode == 94)
				{
					e->camera.direction.x += e->camera.direction.x *
						cos(M_PI / 6) - e->camera.direction.y * sin(M_PI / 6);
					e->camera.direction.y += e->camera.direction.x *
						sin(M_PI / 6) + e->camera.direction.y * cos(M_PI / 6);
					e->camera.direction = vector_normalize(e->camera.direction);
				}
				if (key->keysym.scancode == 90)
				{
					e->camera.direction.z += e->camera.direction.z *
						cos(-M_PI / 6) - e->camera.direction.y * sin(-M_PI / 6);
					e->camera.direction.y += e->camera.direction.z *
						sin(-M_PI / 6) + e->camera.direction.y * cos(-M_PI / 6);
					e->camera.direction = vector_normalize(e->camera.direction);
				}
				status = 3;
			}
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_WINDOWEVENT_CLOSE:
		case SDL_QUIT:
			status = 1;
			break;
		default:
			break;
		}
	}
	return (status);
}
