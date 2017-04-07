/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:11:59 by telain            #+#    #+#             */
/*   Updated: 2017/04/06 17:07:07 by telain           ###   ########.fr       */
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
		return ;
	}
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

/*
** Subcalled by fill_objects
*/

static void		fill_objects_sub2(char **s, t_object *o, int i)
{
	if (i == 8)
		o->comment = parse_string(s);
	else if (i == 9)
		o->width = parse_float(s);
	else if (i == 10)
		o->height = parse_float(s);
	else if (i == 11)
		o->noise = parse_structure(s);
	else if (i == 12)
		o->transparence = parse_float(s);
	else if (i == 13)
		o->refraction = parse_float(s);
	else if (i == 14)
		o->som0 = parse_vector(s);
	else if (i == 15)
		o->som1 = parse_vector(s);
	else if (i == 16)
		o->som2 = parse_vector(s);
	else if (i == 17)
		o->texture = parse_texture(s);
	else if (i == 18)
		o->rotation = get_angle(s);
	else if (i == 19)
		o->angle = get_angle(s);
}

/*
** Subcalled by fill_objects
*/

static void		fill_objects_sub1(char **s, t_object *o)
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
		o->brightness = get_brightness(s);
	else if (index == 6)
		o->intensity = parse_float(s);
	else if (index == 7)
		o->direction = parse_vector(s);
	else
		fill_objects_sub2(s, o, index);
}

/*
** Subfunction called by fill_objects
*/

static void		object_init(t_object *o)
{
	o->type = UNKNOWN;
	o->texture.w = 1;
	o->texture.h = 1;
	o->texture.srf = 0;
	fill_vector(0, &(o->origin), 1);
	fill_vector(0, &(o->direction), 1);
	o->color = 0xFFFFFF;
	o->brightness = 0.0;
	o->reflection = 0.0;
	o->intensity = 0.0;
	o->comment = 0;
	o->width = MAX_SIZE;
	o->height = MAX_SIZE;
	fill_structure(0, &(o->noise), 1);
	o->top_cap = 0;
	o->bot_cap = 0;
	o->transparence = 0.0;
	o->refraction = 1.0;
	fill_vector(0, &(o->som0), 1);
	fill_vector(0, &(o->som1), 1);
	fill_vector(0, &(o->som2), 1);
	fill_texture(0, &(o->texture), 1);
	o->rotation = 0;
}

/*
** Fill the cap of a finished cone
*/

t_object		*fill_cap_cone(t_object *cone, float num)
{
	t_object *cap;

	cap = ft_memalloc(sizeof(t_object));
	cap->type = CIRCLE;
	cap->radius = tan(cone->angle / 2) * cone->height;
	cap->color = cone->color;
	cap->brightness = cone->brightness;
	cap->reflection = cone->reflection;
	cap->comment = num == 1 ? ft_strdup("1") : ft_strdup("2");
	copy_structure(&(cone->noise), &(cap->noise));
	cap->origin = ADD(cone->origin,
			MUL(vector_normalize(cone->direction), cone->height * num * 0.99999));
	cap->direction = MUL(vector_normalize(cone->direction), num);
	cap->direction = vector_normalize(cap->direction);
	cap->transparence = cone->transparence;
	cap->refraction = cone->refraction;
	cap->texture = cone->texture;
	cap->rotation = cone->rotation;
	copy_texture(&(cone->texture), &(cap->texture));
	return (cap);
}

/*
** Fill object with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_objects(char **s, t_object *o, int init)
{
	if (init == 1)
	{
		object_init(o);
		return ;
	}
	else
		fill_objects_sub1(s, o);
}
