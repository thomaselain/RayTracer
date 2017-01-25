/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:41:03 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:18:47 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#include <fill_datas.h>
#define CAMERA		1
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Return a parsed camera (fill missing datas with 0),
** manage camera errors *not-yet*
*/

t_camera		parse_camera(char **string)
{
	t_camera	ret;
	char		*tmp;
	char		*s;
	int			n[3];

	INDEX = -1;
	fill_camera(string, &ret, 1);
	if ((ERR = error_check(CAMERA, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_camera(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			*string = tmp + 1;
			INDEX = -1;
		}
	if (ERR == ERROR)
		ft_putendl("Error : missing or misplaced coma (camera)");
	return (ret);
}
