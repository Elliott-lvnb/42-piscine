/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:06:22 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:08:04 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_is_valid(char **values, char *args, t_coords co, char c)
{
	int		i;
	int		len;
	int		clue[4];

	i = 0;
	len = ft_get_size(args) / 4;
	while (i < len)
	{
		if ((values[i][co.x] == c && i != co.y)
			|| (i != co.x && values[co.y][i] == c))
			return (0);
		i++;
	}
	clue[0] = ft_col(args, len * 4, co.x, 1);
	clue[1] = ft_col(args, len * 4, co.x, 0);
	clue[2] = ft_row(args, len * 4, co.y, 1);
	clue[3] = ft_row(args, len * 4, co.y, 0);
	if (ft_get_col(values, len * 4, co.x, 1) > clue[0]
		|| (co.y + 1 == len && ft_get_col(values, len * 4, co.x, 0) != clue[1])
		|| ft_get_row(values, len * 4, co.y, 1) > clue[2]
		|| (co.x + 1 == len && ft_get_row(values, len * 4, co.y, 0) != clue[3]))
		return (0);
	return (1);
}

int	ft_solve(char **values, char *args, int n, int size)
{
	char	c;
	int		x;
	int		y;
	int		len;

	len = size / 4;
	c = '0';
	x = n % len;
	y = n / len;
	if (n == len * len)
		return (1);
	if (values[y][x] != '0')
		return (ft_solve(values, args, n + 1, size));
	while (++c <= '0' + len)
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
