/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:22:29 by svassal           #+#    #+#             */
/*   Updated: 2017/04/17 20:19:47 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_general_functions.h>
#define VECTOR		0
#define CAMERA		1
#define OBJECT		2
#define SCENE		3
#define STRUCTURE 	5
#define TEXTURE		6

/*
** Return a vector parmeter
*/

static char		*get_vector_param(int param_num)
{
	if (param_num == 1)
		return ("\"x\"");
	if (param_num == 2)
		return ("\"y\"");
	if (param_num == 3)
		return ("\"z\"");
	return (0);
}

/*
** Returns a structure parameter
*/

static char		*get_structure_param(int param_num)
{
	if (param_num == 1)
		return ("\"material_type\"");
	if (param_num == 2)
		return ("\"zoom\"");
	if (param_num == 3)
		return ("\"intensity\"");
	if (param_num == 4)
		return ("\"c\"");
	return (0);
}

/*
** Returns a texture parameter
*/

static char		*get_texture_param(int param_num)
{
	if (param_num == 1)
		return ("\"path\"");
	if (param_num == 2)
		return ("\"scale\"");
	if (param_num == 3)
		return ("\"rotation\"");
	return (0);
}

/*
** Return a camera parameter
*/

static char		*get_camera_param(int param_num)
{
	if (param_num == 1)
		return ("\"origin\"");
	if (param_num == 2)
		return ("\"direction\"");
	if (param_num == 3)
		return ("\"fov\"");
	if (param_num == 4)
		return ("\"filter\"");
	return (0);
}

/*
** Return a parameter, or 0, if arguments are wrong
*/

char			*get_param_list(int type, int param_num)
{
	if (type == VECTOR)
		return (get_vector_param(param_num));
	if (type == CAMERA)
		return (get_camera_param(param_num));
	if (type == OBJECT)
		return (get_object_param(param_num));
	if (type == STRUCTURE)
		return (get_structure_param(param_num));
	if (type == TEXTURE)
		return (get_texture_param(param_num));
	if (type == SCENE)
		return (get_scene_param(param_num));
	return (0);
}
