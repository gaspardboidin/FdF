/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:53:23 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:13:16 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*str;
	char		*buffer;

	if (!s1)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_isset(*start, set))
		start++;
	while (end >= start && ft_isset(*end, set))
		end--;
	len = end - start + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	buffer = str;
	while (len--)
		*buffer++ = *start++;
	*buffer = '\0';
	return (str);
}
