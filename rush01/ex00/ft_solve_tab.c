/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:06:22 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 18:12:50 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

/*
	Renvoie 1 si le caractere aux coordonnees x, y
	respecte bien les regles du jeu et satisfait
	les indices (colx_up, ..., rowy_left)
*/
int	ft_is_valid(char **values, char *args, int x, int y)
{
	int		i;
	int		len;
	int		clue[4];

	i = 0;
	len = ft_get_size(args) / 4;
	while (i < len)
	{
		if ((values[i][x] == values[y][x] && i != y)
			|| (i != x && values[y][i] == values[y][x]))
			return (0);
		i++;
	}
	clue[0] = ft_col(args, len * 4, x, 1);
	clue[1] = ft_col(args, len * 4, x, 0);
	clue[2] = ft_row(args, len * 4, y, 1);
	clue[3] = ft_row(args, len * 4, y, 0);
	if (ft_get_col(values, len * 4, x, 1) > clue[0]
		|| (y + 1 == len && ft_get_col(values, len * 4, x, 0) != clue[1])
		|| ft_get_row(values, len * 4, y, 1) > clue[2]
		|| (x + 1 == len && ft_get_row(values, len * 4, y, 0) != clue[3]))
		return (0);
	return (1);
}

/*
	Resoud le tableau avec le backtracking, renvoie 1
	si une solution a ete trouvee et 0 sinon.
*/
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
	if (values[y][x] != '0' && ft_is_valid(values, args, x, y))
		return (ft_solve(values, args, n + 1, size));
	while (++c <= '0' + len)
	{
		values[y][x] = c;
		if (ft_is_valid(values, args, x, y))
		{
			if (ft_solve(values, args, n + 1, size))
				return (1);
			values[y][x] = '0';
		}
	}
	values[y][x] = '0';
	return (0);
}
