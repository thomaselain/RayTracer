/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:17:57 by svassal           #+#    #+#             */
/*   Updated: 2017/01/14 15:21:14 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ERROR_H
# define PARSE_ERROR_H

/*
** Print a message and clean allocated memory on error
*/

void		error_close(int type, int error);

#endif