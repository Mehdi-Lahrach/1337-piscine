/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:41:21 by elahrach          #+#    #+#             */
/*   Updated: 2023/10/01 17:28:05 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;
	char	c;

	base_len = 0;
	n = nbr;
	if (!is_valid_base(base))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	c = base[n % base_len];
	ft_putchar(c);
}


int main()
{
	ft_putnbr_base(123, "0123456789");
}











