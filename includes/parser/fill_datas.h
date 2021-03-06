/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:51 by svassal           #+#    #+#             */
/*   Updated: 2017/04/19 17:09:23 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_DATAS_H
# define FILL_DATAS_H
# include <core.h>

/*
** Return a parsed structure (fill missing datas with 0)
*/

void			fill_structure(char **s, t_noise *n, int init);

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

/*
** Fill the cap of a finished cylinder
*/

t_object		*fill_cap(t_object *cylinder, float num);

/*
** Checks if the object is a cylinder, and calculates his caps coordinates
** based on the cylinder's coordinates
*/

void			get_cap(t_object *o);

/*
** Allows an inheritance for a structure
*/

void			copy_structure(t_noise *src, t_noise *dest);

/*
** A specific function to get the texture file's name and to manage
** errors properly
*/

void			get_texture(char **s, t_img *n);

/*
** Allows an inheritance for a texture
*/

void			copy_texture(t_img *src, t_img *dest);

/*
** Fill texture with 0 if init is equal to 1, or with the JSON datas elseway
*/

void			fill_texture(char **s, t_img *n, int init);

/*
** Return a parsed texture (fill missing datas with 0)
*/

t_img			parse_texture(char **string);

/*
** Gets a number between 0 and 360 degrees and then converts it in radian
*/

float			get_angle(char **s);

/*
** A specific function for the brightness variable that requires some
** attention from us
*/

float			get_brightness(char **s);

/*
** Fill the cap of a finished cone
*/

t_object		*fill_cap_cone(t_object *cone, float num);

/*
** Fill vector with 0 if init is equal to 1, or with the JSON
** datas elseway for the apex
*/

void			fill_apex(char **s, t_vector4f *v, int init);

#endif
