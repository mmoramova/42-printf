/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:10:54 by mmoramov          #+#    #+#             */
/*   Updated: 2022/10/30 19:42:45 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_putnbrbase(unsigned long n, char specifier);
int ft_putnbr(long n, char specifier);
//int	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int ft_putptr(void * p);
int	ft_putstr(char *s);
int	ft_putchar(int c);

#endif
