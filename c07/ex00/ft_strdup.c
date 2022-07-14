/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:33:37 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/15 00:44:22 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	size;
	char			*dup;
	unsigned int	i;

	size = 0;
	while (src[size])
		size++;
	dup = (char *) malloc((size + 1) * sizeof(char));
	i = 0;
	while (i <= size)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
