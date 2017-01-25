/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:03:06 by svassal           #+#    #+#             */
/*   Updated: 2016/06/06 20:10:33 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_color_fd(char c, const char *color, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putchar_fd(c, fd);
	ft_putstr(RESET);
}
