/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:42:30 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/10 17:32:45 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	if (c >= 32 && c != 127)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	ft_putchar_hex(unsigned char c)
{
	char			*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[(c / 16) % 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putmemory_hex(unsigned char *c)
{
	char			adress[16];
	int				i;
	unsigned long	div;
	char			*hex;

	i = 15;
	div = (unsigned long) c;
	hex = "0123456789abcdef";
	while (i >= 0)
	{
		adress[i] = hex[div % 16];
		div = div / 16;
		--i;
	}
	i++;
	while (i < 16)
	{
		ft_putchar(adress[i]);
		++i;
	}
	write(1, ":", 1);
}

void	ft_putmemory_content(unsigned char *content, int i, int size)
{
	int				j;

	j = 0;
	while (j < 16)
	{
		if (16 * i + j < size)
			ft_putchar_hex(content[16 * i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
	j = 0;
	while (j < 16)
	{
		if (16 * i + j < size)
			ft_putchar(content[16 * i + j]);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*content;

	content = (unsigned char *) addr;
	i = 0;
	while (i * 16 < size)
	{
		ft_putmemory_hex(content + (16 * i));
		write(1, " ", 1);
		ft_putmemory_content(content, i, size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
