/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:07:09 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/06 19:21:47 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_partition(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (tab[j] < pivot)
		{
			ft_swap(tab + i, tab + j);
			i++;
		}
		j++;
	}
	ft_swap(tab + i, tab + high);
	return (i);
}

void	ft_quick_sort(int *tab, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = ft_partition(tab, low, high);
		ft_quick_sort(tab, low, pivot_index - 1);
		ft_quick_sort(tab, pivot_index + 1, high);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_quick_sort(tab, 0, size - 1);
}
