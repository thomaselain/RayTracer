/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:14:56 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:18:07 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <parse_major.h>
#include <fill_datas.h>
#include <parse_general_functions.h>
#define SCENE			3

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
	}
	else
	{
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
		else
			sc->lights = parse_list(s);
	}
}
