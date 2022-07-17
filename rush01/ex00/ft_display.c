/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:12:55 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:43:30 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_rush.h"

/*
	Affiche le caractere c
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
	Affiche la chaine de caracteres str
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

/*
	Affiche le tableau (execute par main a la fin du programme)
*/
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
