/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:07:51 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/19 16:28:25 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	str_to_upper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	str_to_lower(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]) == 1)
		{
			if (new_word == 1)
			{
				str_to_upper(&str[i]);
				new_word = 0;
			}
			else
				str_to_lower(&str[i]);
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
