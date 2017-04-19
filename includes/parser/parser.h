/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:38:10 by svassal           #+#    #+#             */
/*   Updated: 2017/04/19 17:04:53 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <core.h>

/*
** Returns 0 if the extension of the file is .json, otherwise the function will
** return -1
*/

int				check_extension(char *filename);

/*
** Parse the file into a t_scene variable
*/

t_scene			*scene_parse_file(const char *filename);

/*
** Destroy the scene variable
*/

t_scene			*scene_destroy(t_scene *scene);

#endif
