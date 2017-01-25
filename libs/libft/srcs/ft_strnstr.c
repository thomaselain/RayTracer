/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:08:16 by svassal           #+#    #+#             */
/*   Updated: 2016/03/11 12:47:45 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	max;

	index = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	max = ft_strlen(little);
	while (index < len && *big != '\0' && max <= (len - index))
	{
		if (*big == *little)
			if (ft_strncmp(big, little, max) == 0)
				return ((char *)big);
		index++;
		big++;
	}
	return (0);
}
