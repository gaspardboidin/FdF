/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:32 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:12:06 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*array;
	size_t			i;

	array = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}
