/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:10:31 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 10:56:48 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*n_str;
	int		len;
	int		i;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	while (s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == ' ')
		len--;
	i = -1;
	while (s[++i] == '\n' || s[i] == '\t' || s[i] == ' ')
		len--;
	if (len <= 0)
		len = 0;
	if ((n_str = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	s = s + i;
	i = 0;
	while (i < len)
	{
		n_str[i] = *s++;
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
