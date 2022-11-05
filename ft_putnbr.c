/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:24:30 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 17:29:08 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, char specifier)
{
	int	len;

	len = 0;
	if (ft_strchr("di", specifier) && (n < 0))
	{
		len = ft_putchar('-');
		n *= -1;
	}
	if (len == -1)
		return (-1);
	len += ft_putnbrbase((unsigned int)n, specifier);
	return (len);
}
