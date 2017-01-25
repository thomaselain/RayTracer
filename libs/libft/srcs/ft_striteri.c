/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:53:01 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 12:53:51 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*str;

	if (s == 0 || f == 0)
		return ;
	i = 0;
	str = s;
	while (*str != '\0')
	{
		f(i, str);
		i++;
		str++;
	}
}
