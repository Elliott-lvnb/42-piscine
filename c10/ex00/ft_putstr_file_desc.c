/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_file_desc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:14:24 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 20:15:29 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_file_desc(char *str, int file_desc)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(file_desc, str, len);
}
