/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:20:01 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 14:58:11 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#define O_BRACES		n[0]
#define C_BRACES		n[1]
#define O_BRACKETS		n[2]
#define C_BRACKETS		n[3]
#define INDEX			n[4]
#define NO_ERROR		(1)
#define NEUTRAL			(0)
#define ERROR			(-1)

/*
** Sould be called after every detail or object,
** Return ERROR if a coma is misplaced, or NO_ERROR elseway
*/

int			valide_coma(char *s)
{
	int		ret;

	ret = NEUTRAL;
	if (*s == ',' && (*(s + 1) == '\"' || *(s + 1) == '{'))
		ret = NO_ERROR;
	else if (*s == '}' || *s == ']')
		ret = NO_ERROR;
	else
		ret = ERROR;
	return (ret);
}

/*
** Return NO_ERROR if the amout of opening/closing braces/bracket is equal
** Begin with opening brace
*/

static int	braces(char *s)
{
	int		n[5];

	O_BRACES = 1;
	C_BRACES = 0;
	O_BRACKETS = 0;
	C_BRACKETS = 0;
	INDEX = 0;
	while ((*(s + INDEX) != '}' || C_BRACES != O_BRACES) && *(s + INDEX) != 0)
	{
		INDEX++;
		O_BRACES = (*(s + INDEX) == '{') ? (O_BRACES + 1) : (O_BRACES);
		C_BRACES = (*(s + INDEX) == '}') ? (C_BRACES + 1) : (C_BRACES);
		O_BRACKETS = (*(s + INDEX) == '[') ? (O_BRACKETS + 1) : (O_BRACKETS);
		C_BRACKETS = (*(s + INDEX) == ']') ? (C_BRACKETS + 1) : (O_BRACKETS);
	}
	if (O_BRACES == C_BRACES && O_BRACKETS == C_BRACKETS)
		return (NO_ERROR);
	return (ERROR);
}

/*
** Return NO_ERROR if the amout of opening/closing braces/bracket is equal
** Begin with opening bracket
*/

static int	brackets(char *s)
{
	int		n[5];

	O_BRACES = 0;
	C_BRACES = 0;
	O_BRACKETS = 1;
	C_BRACKETS = 0;
	INDEX = 0;
	while ((*(s + INDEX) != ']' || C_BRACKETS != O_BRACKETS)
		&& *(s + INDEX) != 0)
	{
		INDEX++;
		O_BRACES = (*(s + INDEX) == '{') ? (O_BRACES + 1) : (O_BRACES);
		C_BRACES = (*(s + INDEX) == '}') ? (C_BRACES + 1) : (C_BRACES);
		O_BRACKETS = (*(s + INDEX) == '[') ? (O_BRACKETS + 1) : (O_BRACKETS);
		C_BRACKETS = (*(s + INDEX) == ']') ? (C_BRACKETS + 1) : (C_BRACKETS);
	}
	if (O_BRACES == C_BRACES && O_BRACKETS == C_BRACKETS)
		return (NO_ERROR);
	return (ERROR);
}

/*
** Return NO_ERROR if the amout of opening/closing braces/bracket is equal
** Call subfunction according to the first character
*/

int			valide_braces_brackets(char *s)
{
	if (*s == '{')
		return (braces(s));
	if (*s == '[')
		return (brackets(s));
	return (NEUTRAL);
}

/*
** Skip some characters that are not important
*/

void		character_skipper(char **s)
{
	while (ft_iswhitespace(**s))
		(*s)++;
}
