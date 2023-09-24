/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:17:00 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/24 22:41:33 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' )
		return (1);
	return (0);
}

int	convert(char *str, int i)
{
	int	nb;

	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;
	int	sign_counter;

	i = 0;
	nb = 0;
	sign = 1;
	sign_counter = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_counter++;
		i++;
	}
	if (sign_counter % 2 != 0)
		sign = -1;
	nb = convert(str, i);
	return (sign * nb);
}
