/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:56:18 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/15 01:08:05 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	val;
	int	i;

	if (min >= max)
		return (0);
	tab = (int *) malloc((max - min) * sizeof(int));
	val = min;
	i = 0;
	while (i < max - min)
	{
		tab[i] = val;
		i++;
		val++;
	}
	return (tab);
}
/*
int	main(int argc, char *argv[])
{
	int	*tab;
	int	i;
	int	min;
	int	max;

	if (argc > 2)
	{
		i = 0;
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		tab = ft_range(min, max);
		while (i < max - min - 1)
		{
			printf("%d, ", tab[i]);
			i++;
		}
		printf("%d", tab[i]);
	}
	return (0);
}*/
