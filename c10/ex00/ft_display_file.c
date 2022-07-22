/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:08:46 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 20:29:33 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFF_LEN 4096

int	ft_display_file(char *path)
{
	char	buffer[BUFF_LEN];
	int		file_desc;
	int		len;

	file_desc = open(path, O_RDONLY);
	if (file_desc < 0)
		return (0);
	len = read(file_desc, buffer, BUFF_LEN);
	while (len > 0)
	{
		write(1, buffer, len);
		len = read(file_desc, buffer, BUFF_LEN);
	}
	close(file_desc);
	return (1);
}
