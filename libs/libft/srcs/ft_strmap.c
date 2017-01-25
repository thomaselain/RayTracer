/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:56:00 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 13:02:18 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n_str;
	char	*to_read;
	char	*mem;

	if (s == 0 || f == 0)
		return (0);
	to_read = (char *)s;
	if ((n_str = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	mem = n_str;
	while (*to_read != '\0')
	{
		*n_str = f(*to_read);
		n_str++;
		to_read++;
	}
	*n_str = '\0';
	return (mem);
}
