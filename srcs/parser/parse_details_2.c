/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_details_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:55:36 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 19:52:33 by svassal          ###   ########.fr       */
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
** Parses a substring from the parameter string
*/

char			*parse_string(char **string)
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

t_noise_type	parse_noise_type(char **string)
{
	t_noise_type	ret;
	int				index;

	ret = NONE;
	character_skipper(string);
	if (**string != '\"')
		return (ret);
	if (ft_strnstr(*string, "\"PERLIN\"", (index = 8)) != 0)
		ret = PERLIN;
	else if (ft_strnstr(*string, "\"MARBLE\"", (index = 8)) != 0)
		ret = MARBLE;
	else if (ft_strnstr(*string, "\"WOOD\"", (index = 6)) != 0)
		ret = WOOD;
	else if (ft_strnstr(*string, "\"GRID\"", (index = 6)) != 0)
		ret = GRID;
	else
		index = 0;
	*string = *string + index;
	return (ret);
}

t_filter_type	parse_filter_type(char **string)
{
	t_filter_type	ret;
	int				index;

	ret = NO_FILTER;
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
