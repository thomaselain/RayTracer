/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:35:42 by svassal           #+#    #+#             */
/*   Updated: 2017/01/27 15:40:36 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "core.h"

/*
** Check if the ray intersects with the cone given as parameter
*/

float		find_cone_inter(t_ray *r, t_object *o);

/*
** Check if the ray intersects with the cylinder given as parameter
*/

float		find_cylinder_inter(t_ray *r, t_obj *o);

/*
** Check if the ray intersects with the plane given as parameter
*/

float		find_plane_inter(t_ray *r, t_object *o);

#endif