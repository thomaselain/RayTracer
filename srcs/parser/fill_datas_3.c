/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:37:40 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 18:38:25 by svassal          ###   ########.fr       */
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
