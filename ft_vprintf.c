/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:20:12 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 17:22:25 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(va_list a, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(a, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(a, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(a, void *)));
	else if (ft_strchr("diuxX", specifier))
		return (ft_putnbr(va_arg(a, int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}
