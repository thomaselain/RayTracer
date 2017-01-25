/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:13:04 by svassal           #+#    #+#             */
/*   Updated: 2015/12/11 12:56:17 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n_str;
	char			*to_read;
	char			*mem;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	i = 0;
	to_read = (char *)s;
	if ((n_str = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	mem = n_str;
	while (*to_read != '\0')
	{
		*n_str = f(i, *to_read);
		n_str++;
		to_read++;
		i++;
	}
	*n_str = '\0';
	return (mem);
}
