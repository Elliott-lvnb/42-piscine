/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:55 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:09:20 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_col(char *str, int size, int x, int up)
{
	if (up)
		return (str[2 * x]);
	return (str[size / 2 + 2 * x]);
}

int	ft_row(char *str, int size, int y, int left)
{
	if (left)
		return (str[size + 2 * y]);
	return (str[3 * size / 2 + 2 * y]);
}

char	ft_get_col(char **values, int size, int x, int up)
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

char	ft_get_row(char **values, int size, int y, int left)
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
