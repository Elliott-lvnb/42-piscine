/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:55 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/16 17:57:48 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_col(char *str, int size, int x, int up)
{
	if (up)
		return (str[2 * x]);
	return (str[size / 2 + 2 * x]);
}

int	ft_get_row(char *str, int size, int y, int left)
{
	if (left)
		return (str[size + 2 * y]);
	return (str[3 * size / 2 + 2 * y]);
}
