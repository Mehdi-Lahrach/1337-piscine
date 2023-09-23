/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:42:21 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/23 16:42:52 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	if (!dest || !src)
		return (dest);
	len = ft_strlen(dest);
	while (src[i])
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
