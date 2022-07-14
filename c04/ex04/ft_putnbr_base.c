/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:08:27 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/12 01:27:57 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_get_base_size(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

unsigned int	ft_abs(int nbr)
{
	unsigned int	abs;

	if (nbr < 0 && nbr > -2147483648)
		abs = -nbr;
	else if (nbr == -2147483648)
		abs = -2147483648;
	else
		abs = nbr;
	return (abs);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	b_size;
	unsigned int	nb;
	unsigned int	digit[32];
	unsigned int	i;

	b_size = ft_get_base_size(base);
	nb = ft_abs(nbr);
	if (b_size)
	{
		if (nbr < 0)
			ft_putchar('-');
		else if (nb == 0)
			ft_putchar(base[0]);
		i = 0;
		while (nb > 0)
		{
			digit[i] = nb % b_size;
			nb = nb / b_size;
			i++;
		}
		while (i-- > 0)
			ft_putchar(base[digit[i]]);
	}
}
