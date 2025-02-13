/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:41:18 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:12:51 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	if (!src)
		*(char *)src = '\0';
	len = ft_strlen(src);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, len + 1);
	return (dest);
}
