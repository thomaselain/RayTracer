/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:20:15 by svassal           #+#    #+#             */
/*   Updated: 2017/02/06 17:21:37 by telain           ###   ########.fr       */
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
** Parses a substring from the parameter string
*/

char		*parse_string(char **string)
{
	char	*ret;
	int		index;

	index = 1;
	character_skipper(string);
	if (**string != '\"')
		return (0);
	while (*(*string + index) != '\"')
		index++;
	ret = ft_strsub(*string, 1, index - 1);
	*string = *string + index + 1;
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
	else if (ft_strnstr(*string, "\"CIRCLE\"", (index = 8)) != 0)
		ret = CIRCLE;
	else if (ft_strnstr(*string, "\"SQUARE\"", (index = 8)) != 0)
		ret = SQUARE;
	else
		index = 0;
	*string = *string + index;
	return (ret);
}

t_noise_type	parse_noise_type(char **string)
{
	t_type	ret;
	int		index;

	ret = UNKNOWN;
	character_skipper(string);
	if (**string != '\"')
		return (ret);
	if (ft_strnstr(*string, "\"PERLIN\"", (index = 8)) != 0)
		ret = PERLIN;
	else if (ft_strnstr(*string, "\"MARBLE\"", (index = 8)) != 0)
		ret = MARBLE;
	else if (ft_strnstr(*string, "\"WOOD\"", (index = 6)) != 0)	
		ret = WOOD;
	else
		index = 0;
	*string = *string + index;
	return (ret);
}

t_filter_type	parse_filter_type(char **string)
{
	t_type	ret;
	int		index;

	ret = UNKNOWN;
	character_skipper(string);
	if (**string != '\"')
		return (ret);
	if (ft_strnstr(*string, "\"SEPIA\"", (index = 7)) != 0)
		ret = SEPIA;
	else if (ft_strnstr(*string, "\"NEGATIVE\"", (index = 10)) != 0)
		ret = NEGATIVE;
	else if (ft_strnstr(*string, "\"NO_FILTER\"", (index = 11)) != 0)	
		ret = NO_FILTER;
	else if (ft_strnstr(*string, "\"RED_FILTER\"", (index = 12)) != 0)	
		ret = RED_FILTER;
	else if (ft_strnstr(*string, "\"GREEN_FILTER\"", (index = 14)) != 0)	
		ret = GREEN_FILTER;
	else if (ft_strnstr(*string, "\"BLUE_FILTER\"", (index = 13)) != 0)	
		ret = BLUE_FILTER;
	else if (ft_strnstr(*string, "\"BLACK_WHITE\"", (index = 13)) != 0)	
		ret = BLACK_WHITE;
	else
		index = 0;
	*string = *string + index;
	return (ret);
}
