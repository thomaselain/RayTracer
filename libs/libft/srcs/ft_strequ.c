/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:17:09 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:09:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	if (s1 == 0 || s2 == 0)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (1);
		}
		str1++;
		str2++;
	}
	return (0);
}
