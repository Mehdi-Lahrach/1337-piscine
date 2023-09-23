/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:44:35 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/23 17:57:40 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!dest || !src)
		return (dest);
	while (dest[len])
		len++;
	while (src[i] && nb > 0)
	{
		dest[len++] = src[i++];
		nb--;
	}
	dest[len] = '\0';
	return (dest);
}
