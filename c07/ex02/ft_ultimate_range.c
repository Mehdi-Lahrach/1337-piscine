/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:45:40 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/30 20:21:54 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	tab = malloc(sizeof(int) * size);
	if (!tab)
	{
		*range = NULL;
		return (-1);
	}
	i = min;
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	*range = tab;
	return (size);
}
