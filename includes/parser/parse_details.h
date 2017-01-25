/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_details.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:18:31 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 14:48:26 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DETAILS_H
# define PARSE_DETAILS_H
# include <core.h>

/*
** Parses an integer from the parameter string
*/

int			parse_int(char **string);

/*
** Parses a floating point number from the parameter string
*/

float		parse_float(char **string);

/*
** Parses a hexadecimal number from the parameter string
*/

int			parse_hexa(char **string);

/*
** Parses a substring from the parameter string
*/

char		*parse_string(char **string);

/*
** Parses an object's type from parameter string
*/

t_type		parse_type(char **string);

#endif