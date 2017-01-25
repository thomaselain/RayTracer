/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:33:45 by svassal           #+#    #+#             */
/*   Updated: 2016/03/11 14:51:36 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizecalc(int n, int b)
{
	int		size;

	size = 2;
	if (n < 0)
		size++;
	while (n > b || n < -(b))
	{
		size++;
		n = n / b;
	}
	return (size);
}

char		*ft_itoabase(int n, int b)
{
	char	*ret;
	char	*base;
	int		index[2];

	base = "0123456789ABCDEF";
	index[0] = 0;
	index[1] = 0;
	if ((ret = malloc(sizeof(char) * ft_sizecalc(n, b))) == 0)
		return (0);
	if (n < 0)
		ret[ft_sizecalc(n, b) - 2] = '-';
	ret[ft_sizecalc(n, b) - 1] = '\0';
	while (n >= b || n <= -b)
	{
		index[1] = ft_abs(n % b);
		ret[index[0]] = base[index[1]];
		n = n / b;
		index[0]++;
	}
	ret[index[0]] = base[ft_abs(n)];
	ft_strrev(ret);
	return (ret);
}
