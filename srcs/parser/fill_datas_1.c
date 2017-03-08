/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:35:30 by svassal           #+#    #+#             */
/*   Updated: 2017/03/02 17:50:11 by telain           ###   ########.fr       */
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

/*
** Fill vector with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_vector(char **s, t_vector4f *v, int init)
{
	int		xyz;

	if (init == 1)
	{
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	else
	{
		if (ft_strnstr(*s, "\"x\"", 3) != 0)
			xyz = 1;
		else if (ft_strnstr(*s, "\"y\"", 3) != 0)
			xyz = 2;
		else
			xyz = 3;
		*s = ft_strchr(*s, ':') + 1;
		if (xyz == 1)
			v->x = parse_float(s);
		else if (xyz == 2)
			v->y = parse_float(s);
		else
			v->z = parse_float(s);
	}
}

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
	}
	else
	{
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
}

/*
** Subcalled by fill_objects_sub
*/

static void		fill_objects_sub(char **s, t_object *o)
{
	int		index;
	char	*str;

	index = 0;
	while ((str = get_param_list(OBJECT, ++index)) != 0)
		if ((str = ft_strnstr(*s, str, ft_strlen(str))) != 0)
			break ;
	*s = ft_strchr(*s, ':') + 1;
	if (index == 1)
		o->type = parse_type(s);
	else if (index == 2)
		o->color = parse_hexa(s);
	else if (index == 3)
		o->origin = parse_vector(s);
	else if (index == 4)
		o->reflection = parse_float(s);
	else if (index == 5)
		o->diffuse = parse_float(s);
	else if (index == 6)
		o->intensity = parse_float(s);
	else if (index == 7)
		o->direction = parse_vector(s);
	else if (index == 8)
		o->comment = parse_string(s);
	else if (index == 9)
		o->width = parse_float(s);
	else if (index == 10)
		o->height = parse_float(s);
	else if (index == 11)
		o->noise = parse_structure(s);
	else if (index == 12)
		o->transparence = parse_float(s);
	else if (index == 13)
		o->refraction = parse_float(s);
	else if (index == 14)
		o->som0 = parse_vector(s);
	else if (index == 15)
		o->som1 = parse_vector(s);
	else if (index == 16)
		o->som2 = parse_vector(s);
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
	cap->diffuse = cylinder->diffuse;
	cap->reflection = cylinder->reflection;
	cap->intensity = cylinder->intensity;
	cap->comment = num == 1 ? ft_strdup("1") : ft_strdup("2");
	copy_structure(&(cylinder->noise), &(cap->noise));
	cap->origin = ADD(cylinder->origin,
			MUL(vector_normalize(cylinder->direction), cylinder->height * num * 0.999));
	cap->direction = MUL(vector_normalize(cylinder->direction), num);
	cap->direction = vector_normalize(cap->direction);
	cap->transparence = cylinder->transparence;
	cap->refraction = cylinder->refraction;
	return (cap);
}

/*
** Fill object with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_objects(char **s, t_object *o, int init)
{
	if (init == 1)
	{
		o->type = UNKNOWN;
		fill_vector(0, &(o->origin), 1);
		fill_vector(0, &(o->direction), 1);
		o->color = 0xFFFFFF;
		o->diffuse = 0.0;
		o->reflection = 0.0;
		o->intensity = 0.0;
		o->comment = "NONE";
		o->width = MAX_SIZE;
		o->height = MAX_SIZE;
		fill_structure(0, &(o->noise), 1);
		o->top_cap = NULL;
		o->bot_cap = NULL;
		o->transparence = 0.0;
		o->refraction = 1.0;
		fill_vector(0, &(o->som0), 1);
		fill_vector(0, &(o->som1), 1);
		fill_vector(0, &(o->som2), 1);
	}
	else
		fill_objects_sub(s, o);
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
