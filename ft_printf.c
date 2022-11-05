/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:42:36 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/05 17:17:12 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	int		counter;
	va_list	a;

	i = 0;
	len = 0;
	counter = 0;
	va_start (a, str);
	while (str[i] && counter != -1)
	{
		if (str[i] != '%')
			counter = ft_putchar(str[i]);
		else
			counter = ft_vprintf(a, str[++i]);
		len += counter;
		i++;
	}
	va_end (a);
	if (counter == -1)
		return (-1);
	return (len);
}
