/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:25 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/07 17:55:33 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomb(char comb[10], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, comb + i, 1);
		i++;
	}
}

void	ft_update_combn(char comb[10], int n)
{
	int	i;
	int	updated;

	updated = 0;
	i = n - 1;
	while (i >= 0 && !updated)
	{
		if (comb[i] < '9' - n + i + 1)
		{
			comb[i]++;
			updated = 1;
		}
		else
			--i;
	}
	while (updated && i < n - 1)
	{
		comb[i + 1] = comb[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];
	int		i;

	i = 0;
	while (i < n)
	{
		comb[i] = '0' + i;
		i++;
	}
	while (comb[0] < '9' - n + 1)
	{
		ft_putcomb(comb, n);
		ft_putchar(',');
		ft_putchar(' ');
		ft_update_combn(comb, n);
	}
	ft_putcomb(comb, n);
}
