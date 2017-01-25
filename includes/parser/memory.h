/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:26:20 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:29:13 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include <core.h>

/*
** Control datas parsed from the scene anywhere
*/

t_scene		*scene_content(int action);

/*
** Keep datas parsed from the scene in a string accessible anywhere
*/

char		*scene_string(int action, char *s);

#endif
