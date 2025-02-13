/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:45:35 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:11:58 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	if (!format)
		return (0);
	total_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_len += ft_parse_and_print(format[++i], args);
			i++;
		}
		else
		{
			ft_print_char(format[i]);
			total_len++;
			i++;
		}
	}
	va_end(args);
	return (total_len);
}
