/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions_4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:22:29 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 20:11:10 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*get_object_param_sub(int param_num)
{
	if (param_num == 8)
		return ("\"comment\"");
	if (param_num == 9)
		return ("\"width\"");
	if (param_num == 10)
		return ("\"height\"");
	if (param_num == 11)
		return ("\"material\"");
	if (param_num == 12)
		return ("\"transparence\"");
	if (param_num == 13)
		return ("\"refraction\"");
	if (param_num == 14)
		return ("\"som0\"");
	if (param_num == 15)
		return ("\"som1\"");
	if (param_num == 16)
		return ("\"som2\"");
	if (param_num == 17)
		return ("\"texture\"");
	if (param_num == 18)
		return ("\"rotation\"");
	if (param_num == 19)
		return ("\"angle\"");
	return (0);
}

/*
** Return an object parameter (might be a light)
*/

char		*get_object_param(int param_num)
{
	if (param_num == 1)
		return ("\"type\"");
	if (param_num == 2)
		return ("\"color\"");
	if (param_num == 3)
		return ("\"origin\"");
	if (param_num == 4)
		return ("\"reflection\"");
	if (param_num == 5)
		return ("\"brightness\"");
	if (param_num == 6)
		return ("\"radius\"");
	if (param_num == 7)
		return ("\"direction\"");
	else
		return (get_object_param_sub(param_num));
	return (0);
}

/*
** Return a scene parameter
*/

char		*get_scene_param(int param_num)
{
	if (param_num == 1)
		return ("\"camera\"");
	if (param_num == 2)
		return ("\"objects\"");
	if (param_num == 3)
		return ("\"lights\"");
	if (param_num == 4)
		return ("\"background\"");
	return (0);
}
