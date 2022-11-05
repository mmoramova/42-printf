/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:27:03 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 17:28:24 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_choosebase(char specifier)
{
	char	*base_set;

	if (ft_strchr("px", specifier))
		base_set = "0123456789abcdef";
	else if (specifier == 'X')
		base_set = "0123456789ABCDEF";
	else
		base_set = "0123456789";
	return (base_set);
}
