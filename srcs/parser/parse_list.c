/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:47:39 by svassal           #+#    #+#             */
/*   Updated: 2017/01/26 20:33:17 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#include <fill_datas.h>
#define LIST		4
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Return a parsed list,
** manage list errors *not-yet*
*/

t_list			*parse_list(char **string)
{
	t_list		*ret;
	int			n[3];
	char		*s;
	char		*tmp;

	ret = 0;
	if ((ERR = valide_braces_brackets(*string)) == ERROR)
		return (ret);
	if ((LENGTH = get_param_length(*string)) == ERROR)
		return (ret);
	INDEX = -1;
	s = *string;
	while (*string + ++INDEX < s + LENGTH)
		if (*(*string + INDEX) == '{')
		{
			tmp = *string + INDEX;
			fill_list(&tmp, &ret);
			ERR = (valide_coma(tmp) == ERROR) ? (ERROR) : (NO_ERROR);
			if (ERR == ERROR)
				error_close(LIST, CEC);
			*string = tmp + 1;
			INDEX = -1;
		}
	return (ret);
}
