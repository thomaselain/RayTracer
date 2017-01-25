/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:49:45 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:09:49 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (s1 == 0 || s2 == 0)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (*str1 == *str2 && n > 0)
	{
		if (*str1 == '\0')
		{
			return (1);
		}
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (1);
	return (0);
}
