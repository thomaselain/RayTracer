/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:45:48 by svassal           #+#    #+#             */
/*   Updated: 2016/06/06 19:52:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_color_fd(char const *s, char const *c, int fd)
{
	ft_putstr_color_fd(s, c, fd);
	ft_putstr_fd("\n", fd);
}
