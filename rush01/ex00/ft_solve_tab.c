/*                                                        :::      ::::::::   */
/*   ft_solve_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:18:44 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/16 16:22:10 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define "ft_rush.h"

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
	return (1);
}

char	ft_compute_col(char **values, int size, int x, int up)
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

char	ft_compute_row(char **values, int size, int y, int left)
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

int	ft_is_final(char **values, char *args, int size)
{
	int	i;

	i = 0;
	while (i < size / 4)
	{
		if (ft_compute_row(values, size, i, 1) != ft_get_row(args, size, i, 1))
			return (0);
		if (ft_compute_row(values, size, i, 0) != ft_get_row(args, size, i, 0))
			return (0);
		if (ft_compute_col(values, size, i, 1) != ft_get_col(args, size, i, 1))
			return (0);
		if (ft_compute_col(values, size, i, 0) != ft_get_col(args, size, i, 0))
			return (0);
		i++;
	}
	return (1);
}
