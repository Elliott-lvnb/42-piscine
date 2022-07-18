/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:17:58 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/15 20:29:11 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;
	int		j;
	int		k;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	str = (char *) malloc((len + 1 + (size * ft_strlen(sep)) * sizeof(char)));
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[j])
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j])
		{
			str[k + j] = sep[j];
			j++;
		}
		k += j;
		i++;
	}
	str[k] = '\0';
	return (str);
}
