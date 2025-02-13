/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:45:34 by gaboidin          #+#    #+#             */
/*   Updated: 2025/01/30 16:13:46 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_parse_and_print(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}
