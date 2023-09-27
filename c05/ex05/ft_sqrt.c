/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:05:45 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/27 00:20:35 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	i = 1;
	if (nb < 0)
		return (0);
	while (1)
	{
		sqrt = i * i;
		if (sqrt == nb)
			return (i);
		else if (sqrt > nb)
			return (0);
		i++;
	}
}
