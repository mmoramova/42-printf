/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:10:54 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 19:02:32 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_putchar(int c);
size_t	ft_strlen(const char *s); //libft
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c); //libft
int		ft_putptr(void *p);
char	*ft_choosebase(char specifier);
int		ft_putnbrbase(unsigned long n, char specifier);
int		ft_putnbr(long n, char specifier);
int		ft_vprintf(va_list a, char specifier);
int		ft_printf(const char *str, ...);

#endif
