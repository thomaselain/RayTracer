/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:44:06 by svassal           #+#    #+#             */
/*   Updated: 2016/03/11 13:48:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			index;

	index = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2 && index < n && *ss1 != '\0')
	{
		ss1++;
		ss2++;
		index++;
	}
	if (index == n)
		return (0);
	return ((int)(*ss1 - *ss2));
}
