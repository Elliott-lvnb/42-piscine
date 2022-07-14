/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:18:28 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/14 15:15:06 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_is_valid(int n, int i, int pos[10])
{
	int		j;

	j = 0;
	while (j < n)
	{
		if (pos[j] == i)
			return (0);
		if (ft_abs(pos[j] - i) == ft_abs(j - n))
			return (0);
		j++;
	}
	return (1);
}

int	ft_ten_queens(int n, int pos[10])
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (n == 10)
	{
		while (i++ < 10)
			ft_putchar(pos[i - 1] + '0');
		ft_putchar('\n');
		return (1);
	}
	else
	{
		while (i++ < 10)
		{
			if (ft_is_valid(n, i - 1, pos))
			{
				pos[n] = i - 1;
				count += ft_ten_queens(n + 1, pos);
			}
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];

	return (ft_ten_queens(0, pos));
}
