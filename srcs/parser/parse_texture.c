/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <cchicote@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:22:31 by cchicote           #+#    #+#            */
/*   Updated: 2017/03/22 21:00:43 by cchicote           ###   ########.fr     */
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
#define TEXTURE		6
#define CEC			5
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** A specific function to get the texture file's name and to manage errors properly
*/

void			get_texture(char **s, t_img *n)
{
	if (img_init_bmp(n, parse_string(s)) != 1)
		error_close(2, 1);
}

/*
** Allows an inheritance for a texture
*/

void			copy_texture(t_img *src, t_img *dest)
{
	if (src && dest)
	{
		dest->srf = src->srf;
		dest->w = src->w;
		dest->h = src->h;
		dest->scale = src->scale;
	}
}

/*
** Fill texture with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_texture(char **s, t_img *n, int init)
{
	int		data_i;

	data_i = 0;
	if (init == 1)
	{
		n->srf = NULL;
		n->w = 1.0;
		n->h = 1.0;
		n->scale = 1.0;
	}
	else
	{
		if (ft_strnstr(*s, "\"path\"", 6) != 0)
			data_i = 1;
		else if (ft_strnstr(*s, "\"scale\"", 7) != 0)
			data_i = 2;
		*s = ft_strchr(*s, ':') + 1;
		if (data_i == 1)
			get_texture(s, n);
		else if (data_i == 2)
			n->scale = parse_float(s);
	}
}

/*
** Return a parsed texture (fill missing datas with 0)
*/

t_img				parse_texture(char **string)
{
	t_img			ret;
	char			*tmp;
	char			*s;
	int				n[3];

	INDEX = -1;
	fill_texture(string, &ret, 1);
	character_skipper(string);
	if ((ERR = error_check(TEXTURE, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_texture(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			if (ERR == ERROR)
				error_close(TEXTURE, CEC);
			*string = tmp + 1;
			INDEX = -1;
		}
	return (ret);
}