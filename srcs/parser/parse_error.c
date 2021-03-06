/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:10:04 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 19:53:37 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <libft.h>
#include <memory.h>
#define GET			0
#define INIT		1
#define CLEAN		2
#define SET			3
#define VECTOR		0
#define CAMERA		1
#define OBJECT		2
#define TEXTURE		6
#define LIGHT		OBJECT
#define STRUCT		5
#define SCENE		3
#define LIST		4
#define BBC			0
#define EPC			1
#define CPC			2
#define CEC			3
#define BP			4

/*
** Return some text according to the error given as parameter
*/

void			display_error(int errnum)
{
	if (errnum == 1)
		ft_putendl("Wrong format. Use the '.json' format.");
	else if (errnum == 2)
		ft_putendl("The file is empty.");
	if (errnum != 0)
		exit(0);
}

static char		*error_text(int error)
{
	if (error == BBC)
		return ("can't match braces or brackets");
	if (error == EPC)
		return ("found a non existing parameter");
	if (error == CPC)
		return ("found multiple occurence of the same parameter");
	if (error == CEC)
		return ("missing or missplaced coma");
	if (error == BP)
		return ("wrong parameter value");
	return (0);
}

/*
** Return some text according to the type given as parameter
*/

static char		*type_text(int type)
{
	if (type == VECTOR)
		return (" for a vector.");
	if (type == CAMERA)
		return (" for the camera.");
	if (type == OBJECT)
		return (" for an object.");
	if (type == SCENE)
		return (" for the global scene.");
	if (type == LIST)
		return (" for one of the lists.");
	if (type == STRUCT)
		return (" for the structure.");
	if (type == TEXTURE)
		return (" for the texture.");
	return (0);
}

/*
** Print a message and clean allocated memory on error
*/

void			error_close(int type, int error)
{
	ft_putstr_fd("Error parsing json file : ", 2);
	ft_putstr_fd(error_text(error), 2);
	ft_putendl_fd(type_text(type), 2);
	scene_content(CLEAN);
	scene_string(CLEAN, 0);
	exit(1);
}
