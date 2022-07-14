/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:45 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/12 16:42:09 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_get_base_size(char *base)
{
	int				i;
	int				j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_is_whitespace(base[i]))
			return (0);
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_is_positive(char *str)
{
	int				i;
	int				sign;

	i = 0;
	sign = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	return (sign % 2 == 0);
}

int	ft_base_char(char c, char *base)
{
	int				i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i] == c)
		return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	char			*tr;
	long long int	res;
	int				b_size;
	int				b_char;

	tr = str;
	b_size = ft_get_base_size(base);
	while (*tr && (ft_is_whitespace(*tr) || *tr == '+' || *tr == '-'))
		tr++;
	if (*tr && b_size > 1)
	{
		res = 0;
		b_char = ft_base_char(*tr, base);
		while (*tr && b_char != -1)
		{
			res = b_size * res + b_char;
			tr++;
			b_char = ft_base_char(*tr, base);
		}
		if (ft_is_positive(str))
			return ((int) res);
		return ((int) - res);
	}
	return (0);
}
