/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:37:40 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 19:49:12 by svassal          ###   ########.fr       */
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
** A specific function for the brightness variable that requires some
** attention from us
*/

float			get_brightness(char **s)
{
	float		b;

	b = parse_float(s);
	if (b <= 0)
		return (0.0);
	if (b >= 1.0)
		b = 1.0;
	return (1200.0 - b * 1200.0 + 10.0);
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
			MUL(vector_normalize(cone->direction), cone->height * num
				* 0.99999));
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
** Fill vector with 0 if init is equal to 1, or with the JSON
** datas elseway for the apex
*/

void			fill_apex(char **s, t_vector4f *v, int init)
{
	int		xyz;

	if (init == 1 || init == 2 || init == 3)
	{
		v->x = 0;
		init == 1 ? v->x = 1 : 0;
		v->y = 0;
		init == 2 ? v->y = 1 : 0;
		v->z = 0;
		init == 3 ? v->z = 1 : 0;
		return ;
	}
	if (ft_strnstr(*s, "\"x\"", 3) != 0)
		xyz = 1;
	else if (ft_strnstr(*s, "\"y\"", 3) != 0)
		xyz = 2;
	else if (ft_strnstr(*s, "\"z\"", 3) != 0)
		xyz = 3;
	*s = ft_strchr(*s, ':') + 1;
	if (xyz == 1)
		v->x = parse_float(s);
	else if (xyz == 2)
		v->y = parse_float(s);
	else
		v->z = parse_float(s);
}
