/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 00:00:03 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/26 00:00:46 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	ac;

	ac = 1;
	if (argc == 1)
		return (0);
	while (ac < argc)
	{
		ft_putstr(argv[ac]);
		write(1, "\n", 1);
			ac++;
	}
	return (0);
}
