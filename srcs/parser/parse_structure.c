/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <cchicote@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:22:31 by cchicote           #+#    #+#            */
/*   Updated: 2017/02/10 21:00:43 by cchicote           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "parse_major.h"
#include <stdio.h>
#include "parse_general_functions.h"
#include "parse_details.h"
#include "parse_error.h"
#define STRUCT		5
#define CEC			5
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Allows an inheritance for a structure
*/

void			copy_structure(t_noise *src, t_noise *dest)
{
	if (src && dest)
	{
		dest->material_type = src->material_type;
		dest->zoom = src->zoom;
		dest->intensity = src->intensity;
		dest->c = src->c;
	}
}

/*
** Fill structure with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_structure(char **s, t_noise *n, int init)
{
	int		data_i;

	data_i = 0;
	if (init == 1)
	{
		n->material_type = NONE;
		n->zoom = 0.0;
		n->intensity = 1.0;
		n->c = 0.0;
	}
	else
	{
		if (ft_strnstr(*s, "\"material_type\"", 15) != 0)
			data_i = 1;
		else if (ft_strnstr(*s, "\"zoom\"", 6) != 0)
			data_i = 2;
		else if (ft_strnstr(*s, "\"intensity\"", 11) != 0)
			data_i = 3;
		else if (ft_strnstr(*s, "\"c\"", 3) != 0)
			data_i = 4;
		*s = ft_strchr(*s, ':') + 1;
		if (data_i == 1)
			n->material_type = parse_noise_type(s);
		else if (data_i == 2)
			n->zoom = parse_float(s);
		else if (data_i == 3)
			n->intensity = parse_float(s);
		else if (data_i == 4)
			n->c = parse_float(s);
	}
}

/*
** Return a parsed structure (fill missing datas with 0)
*/

t_noise				parse_structure(char **string)
{
	t_noise			ret;
	char			*tmp;
	char			*s;
	int				n[3];

	INDEX = -1;
	fill_structure(string, &ret, 1);
	character_skipper(string);
	if ((ERR = error_check(STRUCT, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_structure(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			if (ERR == ERROR)
				error_close(STRUCT, CEC);
			*string = tmp + 1;
			INDEX = -1;
		}
	return (ret);
}