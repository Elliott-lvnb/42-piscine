/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:17:21 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/15 01:22:02 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	val;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *) malloc((max - min) * sizeof(int));
	if (*range == 0)
		return (-1);
	i = 0;
	val = min;
	while (i < max - min)
	{
		*range[i] = val;
		i++;
		val++;
	}
	return (max - min);
}
