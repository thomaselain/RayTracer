/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:14:56 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 18:39:56 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <ray.h>
#include <libft.h>
#include <parse_general_functions.h>
#include <parse_details.h>
#include <parse_major.h>
#include "fill_datas.h"
#define VECTOR			0
#define CAMERA			1
#define OBJECT			2
#define LIGHT			OBJECT
#define SCENE			3
#define LIST			4
#define STRUCT			5

// #include <core.h>
// #include <libft.h>
// #include <parse_major.h>
// #include <fill_datas.h>
// #include <parse_general_functions.h>
// #include <parse_details.h>
// #define SCENE			3

/*
** Fill camera with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_camera(char **s, t_camera *c, int init)
{
	int		index;
	char	*str;

	if (init == 1)
	{
		fill_vector(0, &(c->origin), 1);
		fill_vector(0, &(c->direction), 1);
		c->fov = 0;
		c->filter = NO_FILTER;
		return ;
	}
	index = 0;
	while ((str = get_param_list(CAMERA, ++index)) != 0)
		if ((str = ft_strnstr(*s, str, ft_strlen(str))) != 0)
			break ;
	*s = ft_strchr(*s, ':') + 1;
	if (index == 1)
		c->origin = parse_vector(s);
	else if (index == 2)
		c->direction = parse_vector(s);
	else if (index == 3)
		c->fov = parse_int(s);
	else if (index == 4)
		c->filter = parse_filter_type(s);
}

/*
** Add elements to the list given as parameter
*/

void			fill_list(char **s, t_list **l)
{
	t_object	*obj;
	t_list		*tmp;

	obj = ft_memalloc(sizeof(t_object));
	*obj = parse_object(s);
	if (obj)
		obj->direction = vector_normalize(obj->direction);
	if (*l == 0)
		*l = ft_lstnew((void *)obj, sizeof(t_object));
	else
	{
		tmp = *l;
		while ((*l)->next != 0)
			*l = (*l)->next;
		obj->direction = vector_normalize(obj->direction);
		ft_lstpushback(l, ft_lstnew((void *)obj, sizeof(t_object)));
		*l = tmp;
	}
	ft_memdel((void**)&obj);
}

/*
** Fill scene with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_scene(char **s, t_scene *sc, int init)
{
	int		index;
	char	*str;

	if (init == 1)
	{
		fill_camera(0, &(sc->camera), 1);
		sc->lights = 0;
		sc->objects = 0;
		return ;
	}
	index = 0;
	while ((str = get_param_list(SCENE, ++index)) != 0)
		if ((str = ft_strnstr(*s, str, ft_strlen(str))) != 0)
			break ;
	*s = ft_strchr(*s, ':') + 1;
	character_skipper(s);
	if (index == 1)
		sc->camera = parse_camera(s);
	else if (index == 2)
		sc->objects = parse_list(s);
	else if (index == 3)
		sc->lights = parse_list(s);
	else
		sc->background = parse_hexa(s);
}

/*
** Fill the cap of a finished cylinder
*/

t_object		*fill_cap(t_object *cylinder, float num)
{
	t_object *cap;

	cap = ft_memalloc(sizeof(t_object));
	cap->type = CIRCLE;
	cap->radius = cylinder->radius;
	cap->color = cylinder->color;
	cap->brightness = cylinder->brightness;
	cap->reflection = cylinder->reflection;
	cap->intensity = cylinder->intensity;
	cap->comment = num == 1 ? ft_strdup("1") : ft_strdup("2");
	copy_structure(&(cylinder->noise), &(cap->noise));
	cap->origin = ADD(cylinder->origin,
			MUL(vector_normalize(cylinder->direction),
				cylinder->height * num * 0.999));
	cap->direction = MUL(vector_normalize(cylinder->direction), num);
	cap->direction = vector_normalize(cap->direction);
	cap->transparence = cylinder->transparence;
	cap->refraction = cylinder->refraction;
	cap->texture = cylinder->texture;
	cap->rotation = cylinder->rotation;
	copy_texture(&(cylinder->texture), &(cap->texture));
	return (cap);
}

/*
** Gets a number between 0 and 360 degrees and then converts it in radian
*/

float			get_angle(char **s)
{
	float		ret;
	float		rad;

	ret = parse_float(s);
	if (ret < 0 || ret > 360)
		error_close(2, 1);
	rad = ret * (M_PI / 180);
	return (rad);
}
