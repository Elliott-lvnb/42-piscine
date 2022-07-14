/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:12:15 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/12 18:54:28 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int	ft_pow10(int n)
{
	long int	p;
	long int	i;

	p = 1;
	i = 0;
	while (i < n)
	{
		p *= 10;
		i++;
	}
	return (p);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	nb_pow;
	long int	long_nb;

	long_nb = nb;
	if (nb == 0)
		ft_putchar('0');
	nb_pow = 0;
	if (long_nb < 0)
	{
		ft_putchar('-');
		long_nb = -long_nb;
	}
	while (long_nb / ft_pow10(nb_pow) > 0)
		nb_pow++;
	nb_pow -= 1;
	while (nb_pow >= 0)
	{
		ft_putchar('0' + (long_nb / ft_pow10(nb_pow)));
		long_nb = long_nb % ft_pow10(nb_pow);
		nb_pow--;
	}
}
