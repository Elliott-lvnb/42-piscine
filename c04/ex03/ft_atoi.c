/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:04 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/12 18:59:45 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_truncate(char *str)
{
	unsigned int	i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	return (str + i);
}

int	ft_is_positive(char *str)
{
	unsigned int	i;
	unsigned int	minus;

	i = 0;
	minus = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	return (minus % 2 == 0);
}

int	ft_atoi(char *str)
{
	char			*str_nw;
	unsigned int	i;
	unsigned int	res;

	str_nw = ft_truncate(str);
	i = 0;
	res = 0;
	if (str_nw)
	{
		while (str_nw[i] >= '0' && str_nw[i] <= '9')
		{
			res = res * 10 + (str_nw[i] - '0');
			i++;
		}
	}
	if (!ft_is_positive(str))
		return ((int) - res);
	return ((int) res);
}
