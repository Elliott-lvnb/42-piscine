/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:57:07 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/14 15:39:01 by eloevenb         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	if (nb > 2)
		next_prime = nb;
	else
		next_prime = 2;
	if (!ft_is_prime(next_prime))
	{	
		if (nb % 2 == 0)
			next_prime++;
		else
			next_prime += 2;
	}
	while (!ft_is_prime(next_prime))
			next_prime += 2;
	return (next_prime);
}
/*
int	main(int argc, char *argv[])
{
	if (argc > 1)
		printf("%d\n", ft_find_next_prime(atoi(argv[1])));
	return (0);
}*/
