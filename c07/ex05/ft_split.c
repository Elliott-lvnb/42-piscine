/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:02:09 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/19 17:57:01 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int	ft_cpy(char **dest, char *src, int size, int i)
{
	int	j;

	j = 0;
	dest[i] = (char *) malloc((size + 1) * sizeof(char));
	if (!dest[i])
		return (0);
	while (src[j] && j < size)
	{
		dest[i][j] = src[j];
		j++;
	}
	dest[i][j] = '\0';
	return (1);
}

int	ft_sep(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_nb_sep(char *str, char *charset)
{
	int		nb_sep;
	int		sep;
	int		prev_sep;

	sep = ft_sep(str, charset);
	prev_sep = -1;
	nb_sep = 0;
	while (sep != prev_sep)
	{
		nb_sep++;
		prev_sep = sep;
		sep += 1 + ft_sep(str + sep + 1, charset);
	}
	return (nb_sep);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_sep;
	char	**strs;
	int		sep;
	int		p_sep;

	nb_sep = ft_nb_sep(str, charset);
	strs = (char **) malloc(nb_sep * sizeof(char *));
	if (!strs)
		return (0);
	strs[nb_sep - 1] = 0;
	nb_sep = 0;
	p_sep = -1;
	sep = ft_sep(str, charset);
	while (sep != p_sep)
	{
		p_sep = sep;
		sep += 1 + ft_sep(str + p_sep + 1, charset);
		if (sep > 1 + p_sep)
			if (!ft_cpy(strs, str + p_sep + 1, sep - p_sep - 1, nb_sep++))
				return (0);
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
