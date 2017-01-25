/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:22:38 by svassal           #+#    #+#             */
/*   Updated: 2015/11/29 13:35:50 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*n_str;
	size_t			i;

	i = 0;
	if ((n_str = malloc(sizeof(unsigned char) * (size + 1))) == 0)
		return (0);
	while (i < (size + 1))
	{
		*(n_str + i) = '\0';
		i++;
	}
	return ((char *)n_str);
}
