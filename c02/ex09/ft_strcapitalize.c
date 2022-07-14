/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:55:47 by eloevenb          #+#    #+#             */
/*   Updated: 2022/07/10 23:30:58 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_char_is_alphanumeric(char c)
{
	if (ft_char_is_lowercase(c))
		return (1);
	return ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int	ft_char_is_first_letter(char *str, int i)
{
	if (i == 0)
		return (1);
	return (!ft_char_is_alphanumeric(str[i - 1]));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_first_letter(str, i))
		{	
			if (ft_char_is_lowercase(str[i]))
				str[i] = str[i] - 'a' + 'A';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}
