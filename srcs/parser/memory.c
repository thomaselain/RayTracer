/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:36:58 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 14:47:36 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <stdio.h>
#define GET		0
#define INIT		1
#define CLEAN		2
#define SET		3

/*
** Clean the memory allocated to the scene datas
*/

static t_scene	*clean(t_scene *scene)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = scene->lights;
	while (scene->lights != 0)
	{
		if (scene->lights->content != 0)
			free(scene->lights->content);
		tmp2 = scene->lights;
		scene->lights = scene->lights->next;
		free(tmp2);
	}
	scene->lights = tmp;
	tmp = scene->objects;
	while (scene->objects != 0)
	{
		if (scene->objects->content != 0)
			free(scene->objects->content);
		tmp2 = scene->objects;
		scene->objects = scene->objects->next;
		free(tmp2);
	}
	scene->objects = tmp;
	scene = 0;
	return (scene);
}

/*
** Control datas parsed from the scene anywhere
*/

t_scene		*scene_content(int action)
{
	static t_scene		scene;

	if (action == GET)
		return (&scene);
	else if (action == INIT)
	{
		scene.lights = 0;
		scene.objects = 0;
	}
	else if (action == CLEAN)
		return (clean(&scene));
	return (0);
}

/*
** Keep datas parsed from the scene in a string accessible anywhere
*/

char		*scene_string(int action, char *s)
{
	static char			*string;

	if (action == GET)
		return (string);
	else if (action == SET)
		string = s;
	else if (action == CLEAN)
	{
		if (string != 0)
			ft_strclr(string);
		return (string);
	}
	return (0);
}
