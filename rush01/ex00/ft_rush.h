/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:57:56 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 13:11:11 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

struct	s_coords {
	int	x;
	int	y;
};

typedef struct s_coords	t_coords;

void	ft_putstr(char *str);
void	ft_putchar(char c);

char	**ft_init_tab(int size);
void	ft_fill_row(char **values, char *args, int size);
void	ft_fill_col(char **values, char *args, int size);
void	ft_put_tab(char **values, int size);
void	ft_destroy_tab(char **values, int size);

int		ft_col(char *str, int size, int x, int up);
int		ft_row(char *str, int size, int y, int left);
char	ft_get_col(char **values, int size, int x, int up);
char	ft_get_row(char **values, int size, int y, int left);

int		ft_get_size(char *str);
int		ft_is_valid_input(char *str, int size);

int		ft_is_valid(char **values, char *args, t_coords coords, char c);
int		ft_solve(char **values, char *args, int n, int size);

#endif
