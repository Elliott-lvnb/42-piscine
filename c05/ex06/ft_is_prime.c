/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:22 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/14 15:41:41 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	nb_l;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb % 2 == 0 && nb != 2)
		return (0);
	nb_l = nb;
	while (i * i <= nb_l)
	{
		if (nb_l % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
int	main(int argc, char *argv[])
{
	if (argc > 1)
		printf("%d\n", ft_is_prime(atoi(argv[1])));
	return (0);
}*/
