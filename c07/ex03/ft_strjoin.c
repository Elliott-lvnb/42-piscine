/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:17:58 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/19 14:26:55 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_join(int size, char **strs, char *sep, char *str)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (i < size - 1 && sep[j])
		{
			str[k + j] = sep[j];
			j++;
		}
		k += j;
		i++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	str = malloc(((len + 1 + (size - 1) * ft_strlen(sep)) * sizeof(char)));
	if (!str)
		return (NULL);
	ft_join(size, strs, sep, str);
	return (str);
}
/*
int	main(int argc, char *argv[])
{
	printf("%s\n", ft_strjoin(argc, argv, "a"));
	return (0);
}*/
