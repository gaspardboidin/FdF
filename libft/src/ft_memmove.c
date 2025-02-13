/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:29:41 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:12:30 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	copy_forward_indexed(unsigned char *dest, const unsigned char *src,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	copy_backward_indexed(unsigned char *dest, const unsigned char *src,
		size_t len)
{
	while (len > 0)
	{
		len--;
		dest[len] = src[len];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (len == 0 || dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
		copy_forward_indexed(d, s, len);
	else if (d > s)
		copy_backward_indexed(d, s, len);
	return (dest);
}
