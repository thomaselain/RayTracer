/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:00:04 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:13:06 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*s;
	char	*mem;

	if (s1 == 0 || s2 == 0)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if ((s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))) == 0)
		return (0);
	mem = s;
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 == '\0')
			*s = *str2++;
		else
			*s = *str1++;
		s++;
	}
	*s = '\0';
	return (mem);
}
