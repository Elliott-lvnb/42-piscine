/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:40 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/19 14:51:06 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

int	ft_is_whitespace(char c);
int	ft_base_index(char c, char *base);
int	ft_base_size(char *base);

int	ft_atoi_base(char *str, char *base, int b_size)
{
	int				i;
	unsigned long	n;
	int				pos;

	pos = 1;
	n = 0;
	while (ft_is_whitespace(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			pos = 1 - pos;
	i = ft_base_index(*str++, base);
	while (i > -1)
	{
		n = n * b_size + i;
		i = ft_base_index(*str++, base);
	}
	if (!pos)
		return ((int) n * -1);
	return ((int) n);
}

int	ft_nb_len(unsigned long int n, int b_size)
{
	int				len;

	len = 1;
	while (n / b_size > 0)
	{
		n /= b_size;
		len++;
	}
	return (len);
}

char	*ft_allocate(int k, unsigned long *n, int *i, int size)
{
	char			*str;

	if (k < 0)
		*n = -k;
	else
		*n = k;
	*i = ft_nb_len(*n, size);
	if (k < 0)
		*i = *i + 1;
	str = (char *) malloc((*i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[*i] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*nb_str;
	unsigned long	n;
	int				k;
	int				size;
	int				i;

	k = ft_base_size(base_from);
	size = ft_base_size(base_to);
	if (!(k && size))
		return (NULL);
	k = ft_atoi_base(nbr, base_from, k);
	nb_str = ft_allocate(k, &n, &i, size);
	if (!nb_str)
		return (NULL);
	while (i-- > 0)
	{
		nb_str[i] = base_to[n % size];
		n = n / size;
	}
	if (k < 0)
		nb_str[0] = '-';
	return (nb_str);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 4)
		printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}*/
