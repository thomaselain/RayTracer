/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:59:44 by svassal           #+#    #+#             */
/*   Updated: 2017/01/26 20:31:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#include <fill_datas.h>
#define OBJECT		2
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Checks if the object is a cylinder, and calculates his caps coordinates based on the cylinder's coordinates
*/

void			get_cap(t_object *o)
{
	if (o->type == CYLINDER) // On place l'initialisation des cap ici puisque si index == 11, c'est qu'on a deja initialise les autres valeurs (type, comment, etc...)
	{
		o->cap1 = ft_memalloc(sizeof(t_object));
		o->cap2 = ft_memalloc(sizeof(t_object));
		fill_cap(o, o->cap1, 1);
		fill_cap(o, o->cap2, 2);
	}
}

/*
** Return a parsed object (fill missing datas with 0),
** manage objects errors *not-yet*
*/

t_object		parse_object(char **string)
{
	t_object	ret;
	int			n[3];
	char		*tmp;
	char		*s;

	INDEX = -1;
	fill_objects(0, &ret, 1);
	if ((ERR = error_check(OBJECT, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_objects(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			if (ERR == ERROR)
				error_close(OBJECT, CEC);
			*string = tmp;
			INDEX = -1;
		}
	get_cap(&ret);
	return (ret);
}
