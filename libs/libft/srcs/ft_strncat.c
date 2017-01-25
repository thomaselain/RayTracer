/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:48:29 by svassal           #+#    #+#             */
/*   Updated: 2016/03/05 14:55:34 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*mem;
	size_t	index;

	mem = s1;
	index = 0;
	if (n != 0)
	{
		while (*s1 != '\0')
			s1++;
		while (*s2 != '\0' && index < n)
		{
			*s1 = *s2;
			s1++;
			s2++;
			index++;
		}
		*s1 = '\0';
	}
	return (mem);
}
