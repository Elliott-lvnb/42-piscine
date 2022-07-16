/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:06:22 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 00:10:06 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_is_valid(char **values, char *args, t_coords coords, char c)
{
	int		i;
	int		size;

	i = 0;
	size = ft_get_size(args);
	while (i < size / 4)
	{
		if ((values[i][coords.x] == c && i != coords.y)
			 || (i != coords.x && values[coords.y][i] == c))
			return (0);
		i++;
	}
	if (ft_cmpt_col(values, size, coords.x, 1) > ft_get_col(args, size, coords.x, 1) || (coords.y + 1 == size / 4
		&& ft_cmpt_col(values, size, coords.x, 0) != ft_get_col(args, size, coords.x, 0))
		|| ft_cmpt_row(values, size, coords.y, 1) > ft_get_row(args, size, coords.y, 1)	|| (coords.x + 1 == size / 4
		&& ft_cmpt_row(values, size, coords.y, 0) != ft_get_row(args, size, coords.y, 0)))
		return (0);
	return (1);
}

char	ft_cmpt_col(char **values, int size, int x, int up)
{
	char	i;
	int		y;
	int		max;

	i = 0;
	max = 0;
	if (up)
		y = 0;
	else
		y = size / 4 - 1;
	while ((up && y < size / 4) || (!up && y >= 0))
	{
		if (values[y][x] > max)
		{
			max = values[y][x];
			i++;
		}
		if (up)
			y++;
		else
			y--;
	}
	return ('0' + i);
}

char	ft_cmpt_row(char **values, int size, int y, int left)
{
	char	i;
	int		x;
	int		max;

	i = 0;
	max = 0;
	if (left)
		x = 0;
	else
		x = size / 4 - 1;
	while ((left && x < size / 4) || (!left && x >= 0))
	{
		if (values[y][x] > max)
		{
			max = values[y][x];
			i++;
		}
		if (left)
			x++;
		else
			x--;
	}
	return (i + '0');
}

int	ft_solve(char **values, char *args, int n, int size)
{
	char	c;
	int		x;
	int		y;

	c = '0';
	x = n % (size / 4);
	y = n / (size / 4);
	if (n == size * size / 16)
		return (1);
	if (values[y][x] != '0')
		return (ft_solve(values, args, n + 1, size));
	while (++c <= '0' + size / 4)
	{
		values[y][x] = c;
		if (ft_is_valid(values, args, (t_coords){x, y}, c))
		{
			if (ft_solve(values, args, n + 1, size))
				return (1);
			values[y][x] = '0';
		}
	}
	values[y][x] = '0';
	return (0);
}
