/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:42:33 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:10:36 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_get_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '9'))
			return (0);
		size++;
		if (str[i + 1] && str[i + 1] != ' ')
			return (0);
		if (str[i + 1])
			i++;
		i++;
	}
	if (size % 4 == 0)
		if (ft_is_valid_input(str, size))
			return (size);
	return (0);
}

int	ft_is_valid_input(char *str, int size)
{
	int		i;
	char	col_up;
	char	col_down;
	char	row_left;
	char	row_right;

	i = 0;
	while (i < size / 4)
	{
		col_up = ft_col(str, size, i, 1);
		col_down = ft_col(str, size, i, 0);
		row_left = ft_row(str, size, i, 1);
		row_right = ft_row(str, size, i, 0);
		if (col_up + col_down - '0' > '1' + size / 4
			|| col_up + col_down - '0' < '3')
			return (0);
		if (row_left + row_right - '0' > '1' + size / 4
			|| row_left + row_right - '0' < '3')
			return (0);
		i++;
	}
	return (1);
}
