/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:02:47 by elahrach          #+#    #+#             */
/*   Updated: 2023/09/24 14:32:18 by elahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	t_len;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	t_len = d_len + s_len;
	if (d_len >= size)
		return (t_len);
	i = d_len;
	while (i < size - 1 && src[i - d_len])
	{
		dest[i] = src[i - d_len];
		i++;
	}
	dest[i] = '\0';
	return (t_len);
}
