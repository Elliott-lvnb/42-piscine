/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:15:30 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:21:21 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	main(int argc, char *argv[])
{
	int		size;
	char	**values;

	if (argc == 2)
	{
		size = ft_get_size(argv[1]);
		if (size > 0)
		{
			values = ft_init_tab(size);
			if (values)
			{
				ft_fill_row(values, argv[1], size);
				ft_fill_col(values, argv[1], size);
				if (ft_solve(values, argv[1], 0, size))
					ft_put_tab(values, size);
				else
					ft_putstr("Error\n");
				ft_destroy_tab(values, size);
				return (0);
			}
		}
	}
	ft_putstr("Error\n");
	return (0);
}
