/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:39:04 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/16 23:17:12 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_rush.h"

char	**ft_init_tab(int size)
{
	int		i;
	int		j;
	char	**values;

	i = 0;
	values = (char **) malloc(size / 4 * sizeof(char *));
	while (i < size / 4)
	{
		values[i] = (char *) malloc(size / 4 * sizeof(char));
		j = 0;
		while (j < size / 4)
		{
			values[i][j] = '0';
			j++;
		}
		i++;
	}
	return (values);
}

void	ft_put_tab(char **values, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size / 4)
	{
		j = 0;
		while (j < size / 4 - 1)
		{
			ft_putchar(values[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar(values[i][j]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_destroy_tab(char **values, int size)
{
	int		i;

	i = 0;
	while (i < size / 4)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

void	ft_fill_col(char **values, char *args, int size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size / 4)
	{
		y = 0;
		if (ft_get_col(args, size, x, 1) == '0' + size / 4)
			while (y++ < size / 4)
				values[y - 1][x] = '0' + y;
		else if (ft_get_col(args, size, x, 1) == '1')
			values[0][x] = '0' + size / 4;
		y = size / 4 - 1;
		if (ft_get_col(args, size, x, 0) == '0' + size / 4)
            while (y-- < size / 4)
                values[y + 1][x] = '0' + y;
        else if (ft_get_col(args, size, x, 0) == '1')
            values[y][x] = '0' + size / 4;
		x++;
	}
}

void	ft_fill_row(char **values, char *args, int size)
{
	int		y;
	int		x;

	y = 0;
	while (y < size / 4)
	{
		x = 0;
		if (ft_get_row(args, size, y, 1) == '0' + size / 4)
			while (x++ < size / 4)
				values[y][x - 1] = '0' + x;
		else if (ft_get_row(args, size, y, 1) == '1')
			values[y][0] = '0' + size / 4;
		x = size / 4 - 1;
		if (ft_get_row(args, size, y, 0) == '0' + size / 4)
            while (x-- < size / 4)
                values[y][x + 1] = '0' + x;
        else if (ft_get_row(args, size, y, 0) == '1')
            values[y][x] = '0' + size / 4;
		y++;
	}
}
