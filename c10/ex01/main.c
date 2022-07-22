/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:03:52 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 22:35:13 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <errno.h>
#include <string.h>
#include <libgen.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*binary;

	binary = basename(argv[0]);
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				if (!ft_display_file(0))
					ft_puterror(strerror(errno), 0, binary);
			}
			else if (!ft_display_file(argv[1]))
				ft_puterror(strerror(errno), argv[i], binary);
			i++;
		}
	}
	else
	{
		if (!ft_display_file(0))
			ft_puterror(strerror(errno), 0, binary);
	}
	return (0);
}
