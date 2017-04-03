/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_details_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:20:15 by svassal           #+#    #+#             */
/*   Updated: 2017/04/02 19:09:32 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parse_general_functions.h>
#include <libft.h>
#define SCENE		3
#define CEC			3
#define INDEX		n[0]
#define ERR			n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)

/*
** Parses an integer from the parameter string
*/

int			parse_int(char **string)
{
	int		index;
	int		ret;

	index = 0;
	character_skipper(string);
	if (**string != '-' && ft_isdigit(**string) != 1)
		return (0);
	if (**string == '-')
		index++;
	while (ft_isdigit(*(*string + index)))
		index++;
	ret = ft_atoi(*string);
	*string = *string + index;
	return (ret);
}

/*
** Parses a floating point number from the parameter string
*/

float		parse_float(char **string)
{
	int		index;
	float	ret;
	int		point;

	point = 0;
	index = 0;
	character_skipper(string);
	if (**string != '-' && ft_isdigit(**string) != 1)
		return (0.0);
	if (**string == '-')
		index++;
	while (ft_isdigit(*(*string + index)) || (*(*string + index) == '.'
		&& point == 0))
	{
		if ((*(*string + index)) == '.')
			point = 1;
		index++;
	}
	ret = (float)atof(*string);
	*string = *string + index;
	return (ret);
}

/*
** Parses a hexadecimal number from the parameter string
*/

int			parse_hexa(char **string)
{
	int index;
	int ret;

	index = 2;
	character_skipper(string);
	if (**string != '0' && ft_tolower(*(*string + 1)) != 'x')
		return (0);
	while (ft_ishexa(*(*string + index)))
		index++;
	ret = ft_atoibase(*string + 2, 16);
	*string = *string + index;
	return (ret);
}

/*
** Subfunction called by parse_type
*/

t_type		sub_parse_type(char **s, int *i)
{
	t_type	ret;

	ret = UNKNOWN;
	if (ft_strnstr(*s, "\"CIRCLE\"", (*i = 8)) != 0)
		ret = CIRCLE;
	else if (ft_strnstr(*s, "\"RECTANGLE\"", (*i = 11)) != 0)
		ret = RECTANGLE;
	else if (ft_strnstr(*s, "\"CUBOID\"", (*i = 8)) != 0)
		ret = CUBOID;
	else if (ft_strnstr(*s, "\"TRIANGLE\"", (*i = 10)) != 0)
		ret = TRIANGLE;
	else
		*i = 0;
	return (ret);
}

/*
** Parses an object's type from parameter string
*/

t_type		parse_type(char **string)
{
	t_type	ret;
	int		index;

	ret = UNKNOWN;
	character_skipper(string);
	if (**string != '\"')
		return (ret);
	if (ft_strnstr(*string, "\"SPOT\"", (index = 6)) != 0)
		ret = SPOT;
	else if (ft_strnstr(*string, "\"DIRECTIONAL\"", (index = 6)) != 0)
		ret = DIRECTIONAL;
	else if (ft_strnstr(*string, "\"PLANE\"", (index = 7)) != 0)
		ret = PLANE;
	else if (ft_strnstr(*string, "\"SPHERE\"", (index = 8)) != 0)
		ret = SPHERE;
	else if (ft_strnstr(*string, "\"CONE\"", (index = 6)) != 0)
		ret = CONE;
	else if (ft_strnstr(*string, "\"CYLINDER\"", (index = 10)) != 0)
		ret = CYLINDER;
	else if (ft_strnstr(*string, "\"DIRECTIONAL\"", (index = 13)) != 0)
		ret = DIRECTIONAL;
	else
		ret = sub_parse_type(string, &index);
	*string = *string + index;
	return (ret);
}
