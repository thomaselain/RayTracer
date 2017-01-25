/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:51 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 14:45:40 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_DATAS
# define FILL_DATAS
# include <core.h>

/*
** Fill vector with 0 if init is equal to zero, or with the JSON datas elseway
*/

void			fill_vector(char **s, t_vector4f *v, int init);

/*
** Fill camera with 0 if init is equal to zero, or with the JSON datas elseway
*/

void			fill_camera(char **s, t_camera *c, int init);

/*
** Fill object with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_objects(char **s, t_object *o, int init);

/*
** Add elements to the list given as parameter
*/

void			fill_list(char **s, t_list **l);

/*
** Fill scene with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_scene(char **s, t_scene *sc, int init);

#endif
