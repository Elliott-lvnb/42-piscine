/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:14:53 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/06 15:59:47 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstring2(char str[2])
{
	write(1, str, 1);
	write(1, str + 1, 1);
}

int	ft_atoi2(char nbr[2])
{
	return ((nbr[0] - '0') * 10 + (nbr[1] - '0'));
}

void	ft_incr_char2(char nbr[2])
{
	if (nbr[1] < '9')
		nbr[1]++;
	else
	{
		nbr[0]++;
		nbr[1] = '0';
	}
}

void	ft_set_char2(char nbr[2], int n)
{
	if (n >= 0 && n < 100)
	{
		nbr[0] = '0' + (n / 10);
		nbr[1] = '0' + (n % 10);
	}
}

void	ft_print_comb2(void)
{
	char	nbr1[2];
	char	nbr2[2];
	char	space;

	space = ' ';
	ft_set_char2(nbr1, 0);
	ft_set_char2(nbr2, 1);
	while (ft_atoi2(nbr1) < ft_atoi2(nbr2))
	{
		ft_set_char2(nbr2, ft_atoi2(nbr1) + 1);
		while (ft_atoi2(nbr2) < 100)
		{
			ft_putstring2(nbr1);
			write(1, &space, 1);
			ft_putstring2(nbr2);
			if (ft_atoi2(nbr1) != 98 || ft_atoi2(nbr2) != 99)
				ft_putstring2(", ");
			ft_incr_char2(nbr2);
		}
		ft_incr_char2(nbr1);
	}
}
