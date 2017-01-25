/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:19:19 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 15:49:01 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	unsigned char	*str;

	if (s == 0)
		return ;
	str = (unsigned char *)s;
	if (ft_strlen(s) != 0)
		write(1, str, ft_strlen(s));
}
