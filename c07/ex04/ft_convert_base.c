/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:49:40 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/18 13:15:31 by eloevenb         ###   ########.fr       */
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*nb_str;
	unsigned long	n;
	int				k;
	int				size;
	int				i;

	k = ft_base_size(base_from);
	size = ft_base_size(base_to)
	if (!(k && size))
		return (NULL);
	k = ft_atoi_base(nbr, base_from, isize);
	n = k < 0 ? -k : k;
	// Trouver longueur de k
	int len;
	nb_str = (char *) malloc((len + 1) * sizeof(char));
	nb_str[len] = '\0';
	i = len;
	while (i-- > 0)
	{
		nb_str[i] = base_to[n % size];
		n = n / size;
	}
	if (n < 0)
		nb_str[0] = '-';
	return (nb_str);
}
