/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:40 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/18 19:48:26 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_base_index(char c, char *base)
{
	int				i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_base_size(char *base)
{
	int				i;

	i = 0;
	while (base[i])
	{
		if (ft_is_whitespace(base[i])
				|| ft_base_index(base[i], base + i + 1) > -1
				|| base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

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

int 	ft_nb_len(int n, int b_size)
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
	n = k < 0 ? -k : k;
	i = ft_nb_len(n, size) + (k < 0 ? 1 : 0);
	nb_str = (char *) malloc((i + 1) * sizeof(char));
	nb_str[i] = '\0';
	while (i-- > 0)
	{
		nb_str[i] = base_to[n % size];
		n = n / size;
	}
	if (n < 0)
		nb_str[0] = '-';
	return (nb_str);
}
