/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:34:58 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/30 20:41:34 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*handel_size_zero(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (size == 0)
		return (handel_size_zero());
	len = ft_strlen(sep) * (size - 1);
	while (i < size)
		len += ft_strlen(strs[i++]);
	res = malloc((sizeof(char) * len) + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(res, sep);
		ft_strcat(res, strs[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
