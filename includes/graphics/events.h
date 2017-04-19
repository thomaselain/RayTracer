/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:40:20 by aljourda          #+#    #+#             */
/*   Updated: 2017/04/19 18:00:40 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include <SDL2/SDL.h>
# include <core.h>

int		key_status_loop(t_scene *e);
int		key_status_progress(void);

#endif
