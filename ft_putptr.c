/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:25:06 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/05 12:29:01 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	len;

	len = ft_putstr((char *)"0x");
	if (len == -1)
		return (-1);
	len += ft_putnbrbase((unsigned long)p, 'p');
	return (len);
}
