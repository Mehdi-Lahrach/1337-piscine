/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:25:00 by elahrach          #+#    #+#             */
/*   Updated: 2023/10/01 17:02:11 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 127 || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sign_spaces(char *str, int *pti)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] >= 9 && (str[i] <= 13 || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*pti = i;
	return (sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	convert(char *str, char *base, int i)
{
	int	nb;
	int	digit;
	int	j;

	nb = 0;
	while (str[i])
	{
		digit = -1;
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				digit = j;
				break ;
			}
			j++;
		}
		if (digit == -1)
			break ;
		nb = nb * ft_strlen(base) + digit;
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;

	if (!is_valid_base(base))
		return (0);
	sign = sign_spaces(str, &i);
	res = convert(str, base, i);
	return (sign * res);
}
