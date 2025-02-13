/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:23 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:13:13 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*last_occurrence;

	ch = (char)c;
	last_occurrence = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			last_occurrence = (char *)&s[i];
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (last_occurrence);
}
