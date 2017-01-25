/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:54:58 by svassal           #+#    #+#             */
/*   Updated: 2016/06/06 20:00:17 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_color_fd(int n, char const *c, int fd)
{
	if (n == -2147483648)
		ft_putstr_color_fd("-2147483648", c, fd);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_color_fd('-', c, fd);
		}
		if (n >= 10)
		{
			ft_putnbr_color_fd((n / 10), c, fd);
			ft_putnbr_color_fd((n % 10), c, fd);
		}
		else
			ft_putchar_color_fd((n + '0'), c, fd);
	}
}
