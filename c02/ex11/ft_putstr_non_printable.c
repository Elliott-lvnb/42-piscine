/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:22:34 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/11 13:24:27 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_non_printable(char c)
{
	char			*hex;
	unsigned char	c_unsigned;

	hex = "0123456789abcdef";
	c_unsigned = (unsigned char) c;
	ft_putchar('\\');
	ft_putchar(hex[(c_unsigned / 16) % 16]);
	ft_putchar(hex[c_unsigned % 16]);
}

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]))
			ft_putchar(str[i]);
		else
			ft_putchar_non_printable(str[i]);
		i++;
	}
}
