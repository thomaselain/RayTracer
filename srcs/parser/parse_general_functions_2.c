/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:41:40 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 16:01:31 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parse_general_functions.h>
#include <parse_error.h>
#define INDEX		n[0]
#define O_BRACES	n[1]
#define C_BRACES	n[2]
#define O_BRACKETS	n[3]
#define C_BRACKETS	n[4]
#define PARAM		n[1]
#define LENGTH		n[2]
#define NO_ERROR	(1)
#define NEUTRAL		(0)
#define ERROR		(-1)
#define BBC			0
#define EPC			1
#define CPC			2
#define CEC			3

/*
** Skip the brackets/braces and their content
*/

void	skip_brackets_braces(char **string)
{
	char	c;

	c = **string;
	(*string)++;
	while (**string != c + 2)
	{
		if (**string == '{' || **string == '[')
			skip_brackets_braces(string);
		(*string)++;
	}
}

/*
** Calcul the length of a JSON parameter, using the brackets and braces
*/

int		get_param_length(char *s)
{
	int		n[5];

	INDEX = 0;
	C_BRACES = 0;
	C_BRACKETS = 0;
	if (*s != '{' && *s != '[')
		return (NEUTRAL);
	O_BRACES = (*s == '{') ? (1) : (0);
	O_BRACKETS = (O_BRACES == 0) ? (1) : (0);
	while ((O_BRACES != C_BRACES || O_BRACKETS != C_BRACKETS) &&
		*(s + ++INDEX) != 0)
	{
		O_BRACES = (*(s + INDEX) == '{') ? (O_BRACES + 1) : (O_BRACES);
		C_BRACES = (*(s + INDEX) == '}') ? (C_BRACES + 1) : (C_BRACES);
		O_BRACKETS = (*(s + INDEX) == '[') ? (O_BRACKETS + 1) : (O_BRACKETS);
		C_BRACKETS = (*(s + INDEX) == ']') ? (C_BRACKETS + 1) : (C_BRACKETS);
	}
	if (*(s + INDEX) == 0)
		return (ERROR);
	return (INDEX);
}

/*
** Return ERROR if multiple occurence of the same parameter is present
*/

int		count_parameters(int type, char *s)
{
	int		param;
	int		length;
	int		cnt;
	char	*tmp;
	char	*r;

	param = 0;
	if ((length = get_param_length(s)) == ERROR)
		return (ERROR);
	while ((tmp = get_param_list(type, ++param)) != 0)
	{
		cnt = 0;
		r = s;
		while ((r = ft_strnstr(r + cnt, tmp, s + length - r)) != 0)
			cnt++;
		if (cnt > 1)
			return (ERROR);
	}
	return (NO_ERROR);
}

/*
** Return ERROR if a parameter that doesn't exist is present, NO_ERROR elseway
*/

int		existing_parameters(int type, char *s)
{
	int		n[3];
	char	*tmp;
	char	*s2;

	s2 = s;
	if ((LENGTH = get_param_length(s)) == ERROR)
		return (ERROR);
	while (++s2 < s + LENGTH)
	{
		if (*s2 == '{' || *s2 == '[')
			skip_brackets_braces(&s2);
		if (*s2 == ':')
		{
			PARAM = 0;
			tmp = 0;
			while ((tmp = get_param_list(type, ++PARAM)) != 0)
				if (ft_strnstr(s2 - ft_strlen(tmp), tmp,
					ft_strlen(tmp)) != 0)
					break ;
			if (tmp == 0)
				return (ERROR);
		}
	}
	return (NO_ERROR);
}

/*
** Return ERROR if errors are found, NO_ERROR elseway
*/

int		error_check(int type, char *s)
{
	int		error;

	error = NO_ERROR;
	if (valide_braces_brackets(s) == ERROR)
	{
		error_close(type, BBC);
		error = ERROR;
	}
	if (existing_parameters(type, s) == ERROR)
	{
		error_close(type, EPC);
		error = ERROR;
	}
	if (count_parameters(type, s) == ERROR)
	{
		error_close(type, CPC);
		error = ERROR;
	}
	return (error);
}
