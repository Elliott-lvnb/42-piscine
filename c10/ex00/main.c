/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:17:27 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 20:20:38 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr_file_desc("File name missing\n", 2);
	else if (argc > 2)
		ft_putstr_file_desc("Too many arguments\n", 2);
	else if (!ft_display_file(argv[1]))
		ft_putstr_file_desc("Cannot read file\n", 2);
	return (0);
}
