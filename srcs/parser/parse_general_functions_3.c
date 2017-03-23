/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:22:29 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 15:55:38 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
** Return an object parameter (might be a light)
*/

static char		*get_object_param(int param_num)
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
	return (0);
}

/*
** Return a scene parameter
*/

static char		*get_scene_param(int param_num)
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
