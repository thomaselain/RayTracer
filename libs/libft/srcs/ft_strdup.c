/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:32:08 by svassal           #+#    #+#             */
/*   Updated: 2016/03/10 15:05:36 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*s2;

	if ((s2 = malloc(sizeof(unsigned char) * (ft_strlen(s1) + 1))) == 0)
		return (0);
	ft_strcpy((char *)s2, s1);
	return ((char *)s2);
}
