/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:09:26 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/16 20:54:11 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	swaped;

	i = 0;
	while (i < size - 1)
	{
		swaped = 0;
		if (tab[i] > tab[i + 1])
		{
			swaped = 1;
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		if (swaped == 0)
		{
			i++;
		}
	}
}
