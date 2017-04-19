/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:17:57 by svassal           #+#    #+#             */
/*   Updated: 2017/04/19 17:10:04 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ERROR_H
# define PARSE_ERROR_H
# include <core.h>

/*
** Print a message and clean allocated memory on error
*/

void		error_close(int type, int error);

/*
** Print a message and exits the function
*/

void		display_error(int errnum);

#endif
