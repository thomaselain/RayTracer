/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:36:27 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:42:05 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char *str;

	str = (char *)s;
	if (s == 0)
		return ;
	if (ft_strlen(s) != 0)
		write(fd, str, ft_strlen(s));
}
