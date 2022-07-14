/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:25:07 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/07 16:26:58 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_char_is_uppercase(str[i]))
			res = 0;
		i++;
	}
	return (res);
}
