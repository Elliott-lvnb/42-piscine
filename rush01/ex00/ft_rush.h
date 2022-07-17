/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:57:56 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/17 18:13:12 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

void	ft_putstr(char *str);
void	ft_putchar(char c);

char	**ft_init_tab(int size);
void	ft_fill_row(char **values, char *args, int size);
void	ft_fill_col(char **values, char *args, int size);
void	ft_put_tab(char **values, int size);
void	ft_destroy_tab(char **values, int size);

char	ft_col(char *args, int size, int x, int up);
char	ft_row(char *args, int size, int y, int left);
char	ft_get_col(char **values, int size, int x, int up);
char	ft_get_row(char **values, int size, int y, int left);

int		ft_get_size(char *args);
int		ft_check_args(char *args, int size);

int		ft_is_valid(char **values, char *args, int x, int y);
int		ft_solve(char **values, char *args, int n, int size);

#endif
