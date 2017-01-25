/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:10:54 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:15:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#include <fill_datas.h>
#define SCENE		3
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Return a parsed scene (fill missing datas with 0),
** manage scene errors *not-yet*
*/

t_scene			parse_scene(char **string)
{
	t_scene		ret;
	int			n[3];
	char		*tmp;
	char		*s;

	INDEX = -1;
	fill_scene(0, &ret, 1);
	if ((ERR = error_check(SCENE, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_scene(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			if (ERR == ERROR)
				break ;
			*string = tmp;
			INDEX = -1;
		}
	if (ERR == ERROR)
		error_close(SCENE, CEC);
	return (ret);
}
