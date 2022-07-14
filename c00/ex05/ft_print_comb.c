/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:27:30 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/07 14:10:59 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstring(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_print_comb(void)
{
	char	digits[3];

	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	while (digits[0] < digits[1] && digits[0] <= '9')
	{
		digits[1] = digits[0] + 1;
		while (digits[1] < digits[2] && digits[1] <= '9')
		{
			digits[2] = digits[1] + 1;
			while (digits[2] <= '9')
			{
				ft_putstring(digits);
				if (!(digits[0] == '7' && digits[1] == '8' && digits[2] == '9'))
					ft_putstring(", ");
				digits[2]++;
			}
			digits[1]++;
		}
		digits[0]++;
	}
}
