/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:55 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 17:55:43 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

/*
	Renvoie l'indice colx_down si up == 0 sinon colx_up
*/
char	ft_col(char *args, int size, int x, int up)
{
	if (up)
		return (args[2 * x]);
	return (args[size / 2 + 2 * x]);
}

/*
	Renvoie l'indice rowy_right si left == 0 sinon rowy_left
*/
char	ft_row(char *args, int size, int y, int left)
{
	if (left)
		return (args[size + 2 * y]);
	return (args[3 * size / 2 + 2 * y]);
}

/*
	Calcule et renvoie colx_up ou colx_down a
	partir des valeurs deja placees dans values 
*/
char	ft_get_col(char **values, int size, int x, int up)
{
	char	i;
	int		y;
	int		max;
	int		len;

	i = 0;
	max = 0;
	len = size / 4;
	if (up)
		y = 0;
	else
		y = len - 1;
	while ((up && y < len) || (!up && y >= 0))
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

/*
	Calcule et renvoie rowy_up ou rowy_down a partir
	des valeurs deja placees dans values
*/
char	ft_get_row(char **values, int size, int y, int left)
{
	char	i;
	int		x;
	int		max;
	int		len;

	i = 0;
	max = 0;
	len = size / 4;
	if (left)
		x = 0;
	else
		x = len - 1;
	while ((left && x < len) || (!left && x >= 0))
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
