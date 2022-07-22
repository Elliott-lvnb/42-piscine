/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:04:24 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/22 22:08:21 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putstr_file_desc(char *str, int file_desc);

void	ft_puterror(char *error, char *path, char *binary);

int		ft_display_file(char *path);

#endif
