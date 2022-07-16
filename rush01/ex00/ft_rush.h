/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:57:56 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/16 19:07:12 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__RUSH_H__
#define	__RUSH_H__

typedef struct {
	int	x;
	int	y;
} t_coords;

void	ft_putstr(char *str);
void	ft_putchar(char c);

int	ft_get_size(char *str);

char	**init_tab(int size);
void	ft_fill_row(char **values, char *args, int size);
void	ft_fill_col(char **values, char *args, int size);
void	ft_put_tab(char **values, int size);
void	ft_destroy_tab(char **values, int size);

int	ft_get_col(char *str, int size, int x, int up);
int	ft_get_row(char *str, int size, int y, int left);


#endif
