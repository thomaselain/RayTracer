/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:38:10 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:23:18 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <core.h>

/*
** Parse the file into a t_scene variable
*/

t_scene			*scene_parse_file(const char *filename);

/*
** Destroy the scene variable
*/

void			scene_destroy(t_scene *scene);

#endif
