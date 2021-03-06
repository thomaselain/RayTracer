/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_major.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:13:54 by svassal           #+#    #+#             */
/*   Updated: 2017/04/19 17:10:45 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAJOR_H
# define PARSE_MAJOR_H
# include <core.h>

/*
** Return a parsed vector (fill missing datas with 0),
** manage vector errors *not-yet*
*/

t_vector4f		parse_vector(char **string);

/*
** Fill structure with 0 if init is equal to 1, or with the JSON datas elseway
*/

t_noise			parse_structure(char **string);

/*
** Return a parsed camera (fill missing datas with 0),
** manage camera errors *not-yet*
*/

t_camera		parse_camera(char **string);

/*
** Return a parsed object (fill missing datas with 0),
** manage object errors *not-yet*
*/

t_object		parse_object(char **string);

/*
** Return a parsed list,
** manage list errors *not-yet*
*/

t_list			*parse_list(char **string);

/*
** Return a parsed scene (fill missing datas with 0),
** manage scene errors *not-yet*
*/

t_scene			parse_scene(char **string);

#endif
