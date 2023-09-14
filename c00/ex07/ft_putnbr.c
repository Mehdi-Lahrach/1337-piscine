/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:03:29 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/14 17:21:19 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_numbers(int j, char numbers[])
{
	int	i;

	i = j - 1;
	while (i >= 0)
	{
		ft_putchar(numbers[i]);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	digit;
	char	numbers[11];

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		digit = nb % 10;
		numbers[i] = '0' + digit;
		i++;
		nb /= 10;
	}
	print_numbers(i, numbers);
}

int	main()
{
	ft_putnbr(15555555);
	return (0);
}
