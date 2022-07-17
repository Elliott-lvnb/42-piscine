/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:42:33 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:44:14 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

/*
	Renvoie le nombre d'indices contenus dans str,
	0 si str est un parametre invalide
*/
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

/*
	Renvoie 1 si str (argv[1]) est un
	parametre valide, 0 sinon
*/
int	ft_is_valid_input(char *str, int size)
{
	int		i;
	char	clue[4];
	int		len;

	i = 0;
	len = size / 4;
	while (i < len)
	{
		clue[0] = ft_col(str, size, i, 1);
		clue[1] = ft_col(str, size, i, 0);
		clue[2] = ft_row(str, size, i, 1);
		clue[3] = ft_row(str, size, i, 0);
		if (clue[0] + clue[1] - '0' > '1' + len
			|| clue[0] + clue[1] - '0' < '3')
			return (0);
		if (clue[2] + clue[3] - '0' > '1' + len
			|| clue[2] + clue[3] - '0' < '3')
			return (0);
		i++;
	}
	return (1);
}
