/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:42:33 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/16 17:20:21 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (0);
		size++;
		if (str[i + 1] && !(str[i + 1] == ' '))
			return (0);
		i += 2;
	}
	if (size % 4 == 0)
		if (ft_is_valid_input(str, size))
			return (size);
	return (0);
}

int	ft_is_valid_input(char *str, int size)
{
	char	p[4];
	int		i;

	i = 0;
	while (i < size / 4)
	{
		p[0] = args[0 * size / 2 + i * 2];
    	p[1] = args[1 * size / 2 + i * 2];
		if (!(p[0] + p[1] > '0' + (size / 4 + 1) && p[0] + p[1] >= '3'))
			return (0);
    	p[2] = args[2 * size / 2 + i * 2];
    	p[3] = args[3 * size / 2 + i * 2];
		if (!(p[2] + p[3] > '0' + (size / 4 + 1) && p[0] + p[1] >= '3'))
			return (0);
		i++;
	}
	return (1);
}
