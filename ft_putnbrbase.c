/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:26:13 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 17:28:51 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase(unsigned long n, char specifier)
{
	int				len;
	unsigned int	base;
	char			*base_set;

	base_set = ft_choosebase(specifier);
	base = ft_strlen(base_set);
	if (n < base)
		return (ft_putchar(base_set[n]));
	else
		len = ft_putnbrbase(n / base, specifier);
	if (len == -1)
		return (-1);
	len += ft_putnbrbase(n % base, specifier);
	return (len);
}
