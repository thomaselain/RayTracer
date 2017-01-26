/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:50:14 by svassal           #+#    #+#             */
/*   Updated: 2017/01/26 20:32:50 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <vector.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#include <fill_datas.h>
#define VECTOR		0
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Return a parsed vector (fill missing datas with 0),
** manage vector errors *not-yet*
*/

t_vector4f		parse_vector(char **string)
{
	t_vector4f		ret;
	char			*tmp;
	char			*s;
	int				n[3];

	INDEX = -1;
	fill_vector(string, &ret, 1);
	character_skipper(string);
	if ((ERR = error_check(VECTOR, *string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '\"')
		{
			tmp = *string + INDEX;
			fill_vector(&tmp, &ret, 0);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (ERR);
			if (ERR == ERROR)
				error_close(VECTOR, CEC);
			*string = tmp + 1;
			INDEX = -1;
		}
	return (ret);
}
