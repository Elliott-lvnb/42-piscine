/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:19:35 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/07 16:21:42 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_char_is_numeric(str[i]))
			res = 0;
		i++;
	}
	return (res);
}
