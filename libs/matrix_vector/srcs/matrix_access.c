/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:35:16 by svassal           #+#    #+#             */
/*   Updated: 2017/01/25 18:57:16 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
** Set the element of the matrix to the value given as parameter
*/

void			matrix_set_elem(t_matrix4f *m, int x, int y, float value)
{
	if (x < 0 || x > 4 || y < 0 || y > 4)
		return ;
	m->data[x][y] = value;
}

/*
** Return the element of the matrix at given element
*/

float			matrix_get_elem(t_matrix4f m, int x, int y)
{
	if (x < 0 || x > 4 || y < 0 || y > 4)
		return (-1);
	return (m.data[x][y]);
}

/*
** Change the full array of the matrix to the one given as parameter
*/

void			matrix_set_array(t_matrix4f *m, float d[4][4])
{
	int		i;
	int		j;

	init_matrix_id(m);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m->data[i][j] = d[i][j];
	}
}
