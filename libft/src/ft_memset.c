/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:10:40 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:12:32 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*array;
	unsigned char	value;
	size_t			i;

	array = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		array[i] = value;
		i++;
	}
	return (s);
}
