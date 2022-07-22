/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:02:09 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/20 18:38:39 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_separator(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	ft_allocate(char ***strs, char *str, char *charset)
{
	int		i;
	int		sep;
	int		nb_string;

	nb_string = 0;
	i = 0;
	sep = 0;
	while (str[i])
	{
		if (ft_is_separator(str[i], charset))
		{
			if (sep < i - 1)
				nb_string++;
			sep = i;
		}
		i++;
	}
	if (sep < i - 1)
		nb_string++;
	*strs = (char **) malloc((nb_string + 1) * sizeof(char *));
	(*strs)[nb_string] = '\0';
	return (nb_string);
}

char	*ft_cpy(char *src, int begin, int end)
{
	int		size;
	char	*dest;
	int		i;

	size = end - begin;
	dest = (char *) malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		dest[i] = src[i + begin];
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		size;
	int		i;
	int		j;
	int		sep;

	size = ft_allocate(&strs, str, charset);
	i = 0;
	j = 0;
	sep = -1;
	while (i < size)
	{
		while (j < ft_strlen(str) && !ft_is_separator(str[j], charset))
			j++;
		if (sep < j - 1 || (sep == -1 && sep < j - 2))
		{
			strs[i] = ft_cpy(str, sep + 1, j);
			i++;
		}
		sep = j;
		j++;
	}
	return (strs);
}
/*
int	main(int argc, char *argv[])
{
	char	**split;
	int		i;

	if (argc == 3)
	{
		split = ft_split(argv[1], argv[2]);
		i = 0;
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	return (0);
}*/
