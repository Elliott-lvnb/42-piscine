/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:08:29 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 22:10:40 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	ft_puterror(char *error, char *path, char *binary)
{
	ft_putstr_file_desc(binary, 2);
	ft_putstr_file_desc(": ", 2);
	ft_putstr_file_desc(path, 2);
	ft_putstr_file_desc(": ", 2);
	ft_putstr_file_desc(error, 2);
	ft_putstr_file_desc("\n", 2);
}
