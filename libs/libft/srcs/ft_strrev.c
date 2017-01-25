/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:35:13 by svassal           #+#    #+#             */
/*   Updated: 2016/03/06 16:26:54 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *c)
{
	int		i;
	int		beg;
	int		end;
	char	tmp;
	int		len;

	i = 0;
	end = (ft_strlen((char const *)c) - 1);
	len = end;
	beg = 0;
	while (i <= (len / 2))
	{
		tmp = c[beg];
		c[beg] = c[end];
		c[end] = tmp;
		i++;
		beg++;
		end--;
	}
}
