/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:46:43 by mmoramov          #+#    #+#             */
/*   Updated: 2022/10/29 18:48:21 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_putnbrbase(long n, int base);
int ft_putnbrbaselong(unsigned long n, unsigned int base, char *base_set);
//int	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int ft_putpointer(void * p);
int	ft_putstr(unsigned char *s);
int	ft_putchar(int c);

#endif
