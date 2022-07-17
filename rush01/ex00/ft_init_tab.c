/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:39:04 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 18:27:20 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_rush.h"

/*
	Initialise le tableau de taille (size / 4) * (size / 4)
*/
char	**ft_init_tab(int size)
{
	int		i;
	int		j;
	char	**values;
	int		len;

	i = 0;
	len = size / 4;
	values = (char **) malloc(len * sizeof(char *));
	while (i < len)
	{
		values[i] = (char *) malloc(len * sizeof(char));
		if (!values[i])
			return (0);
		j = 0;
		while (j < len)
		{
			values[i][j] = '0';
			j++;
		}
		i++;
	}
	return (values);
}

/*
	Detruit le tableau de taille (size / 4) * (size / 4)
*/
void	ft_destroy_tab(char **values, int size)
{
	int		i;
	int		len;

	len = size / 4;
	i = 0;
	while (i < len)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

/*
	Pour tous les colx_up et colx_down qui valent (size / 4),
	Cette fonction remplit les colonnes correspondantes avec
	1, 2, 3, ..., size / 4 ou size / 4, ..., 3, 2, 1
*/
void	ft_fill_col(char **values, char *args, int size)
{
	int		x;
	int		y;
	int		len;

	x = 0;
	len = size / 4;
	while (x < len)
	{
		y = 0;
		if (ft_col(args, size, x, 1) == '0' + len)
			while (y++ < len)
				values[y - 1][x] = '0' + y;
		else if (ft_col(args, size, x, 1) == '1')
			values[0][x] = '0' + len;
		y = len - 1;
		if (ft_col(args, size, x, 0) == '0' + len)
			while (y-- > 0)
				values[y + 1][x] = '0' + y;
		else if (ft_col(args, size, x, 0) == '1')
			values[y][x] = '0' + len;
		x++;
	}
}

/*
	Pour tous les rowy_left et rowy_right qui valent (size / 4),
	Cette fonction remplit les lignes correspondantes avec
	1, 2, 3, ..., size / 4 ou size / 4, ..., 3, 2, 1
*/
void	ft_fill_row(char **values, char *args, int size)
{
	int		y;
	int		x;
	int		len;

	y = 0;
	len = size / 4;
	while (y < len)
	{
		x = 0;
		if (ft_row(args, size, y, 1) == '0' + len)
			while (x++ < len)
				values[y][x - 1] = '0' + x;
		else if (ft_row(args, size, y, 1) == '1')
			values[y][0] = '0' + len;
		x = len - 1;
		if (ft_row(args, size, y, 0) == '0' + len)
			while (x-- > 0)
				values[y][x + 1] = '0' + x;
		else if (ft_row(args, size, y, 0) == '1')
			values[y][x] = '0' + len;
		y++;
	}
}
