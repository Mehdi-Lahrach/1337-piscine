/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:59 by elahrach          #+#    #+#             */
/*   Updated: 2023/10/03 16:23:13 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*copy;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	copy = malloc((sizeof(src) * len) + 1);
	if (!copy)
		return (NULL);
	len = 0;
	while (src[len])
	{
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*my_struct;

	i = 0;
	my_struct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!my_struct)
		return (NULL);
	while (i < ac)
	{
		my_struct[i].size = ft_strlen(av[i]);
		my_struct[i].str = av[i];
		my_struct[i].copy = ft_strdup(av[i]);
		if (!my_struct[i].copy)
		{
			j = 0;
			while (j < i)
				free(my_struct[j++].copy);
			free(my_struct);
			return (NULL);
		}
		i++;
	}
	my_struct[ac].str = 0;
	return (my_struct);
}
