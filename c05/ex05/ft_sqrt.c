/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:37:53 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/14 15:12:57 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int		low;
	long long int		high;
	long long int		mid;
	long long int		nb_l;

	low = 0;
	high = nb;
	mid = (low + high) / 2;
	if (nb < 0)
		return (0);
	nb_l = nb;
	while (low < high)
	{
		if (mid * mid < nb_l)
			low = mid + 1;
		else if (mid * mid > nb_l)
			high = mid - 1;
		else
			return (mid);
		mid = (low + high) / 2;
	}
	if (low * low == nb_l)
		return ((int) low);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	printf("%d\n", ft_sqrt(atoi(argv[1])));
	return (0);
}*/
