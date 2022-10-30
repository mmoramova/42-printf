/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:42:36 by mmoramov          #+#    #+#             */
/*   Updated: 2022/10/30 14:33:31 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(unsigned char *s)
{
	int	len;
	len = 0;
	
	if (!s)
	{
		len = 6;
		write(1, "(null)", len);
		return (len);
	}
	while (*s)
		len += ft_putchar(*s++);
	return (len);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_putpointer(void * p)
{
	int len;
	len = 0;
	//unsigned char *x;

	//x = "0x";
	len += ft_putstr((unsigned char *)"0x");
	len += ft_putnbrbaselong((unsigned long long)p, 16, "0123456789abcdef");
	//printf("\n4: %p\n", p);
	return(len);
}

int ft_putnbrbase(long n, int base)
{
	long	nbr;
	int		len;
	char	*base_set;

	if (base == 10)
		base_set = "0123456789";
	else if (base == 16)
		base_set = "0123456789abcdef";
		
	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		len += 1;
	}
	if (nbr < base)
	{
		len += ft_putchar(base_set[nbr]);
	}
	else
	{
		len += ft_putnbrbase(nbr / base, base);
		len += ft_putnbrbase(nbr % base, base);
	}
	return (len);	
}

int ft_putnbrbaselong(unsigned long n, unsigned int base, char *base_set)
{
	unsigned long nbr;
	int		len;
	//char	*base_set;

	/*if (base == 10)
		base_set = "0123456789";
	else if (base == 16)
		base_set = "0123456789abcdef";
	else if (base == 17)
	{
		base_set = "0123456789ABCDEF";
		base -= 1;
	}*/
	len = 0;
	nbr = n;
	/*if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		len += 1;
	}*/
	if (nbr < base)
	{
		len += ft_putchar(base_set[nbr]);
	}
	else
	{
		len += ft_putnbrbaselong(nbr / base, base, base_set);
		len += ft_putnbrbaselong(nbr % base, base, base_set);
	}
	return (len);
}

int ft_printf(const char *str, ...)
{
	int i;
	int len;
	va_list a;
	
	i = 0;
	len = 0;
	va_start (a, str);

	while (str[i])
	{
		if (str[i] != '%') //ok
			len += ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] == 'c') //ok
				len += ft_putchar(va_arg(a, int));
			else if (str[i] == 's') //ok
				len += ft_putstr(va_arg(a, unsigned char*));
			else if (str[i] == 'p') //ok
				len += ft_putpointer(va_arg(a,unsigned int*));
			else if (str[i] == 'd' || str[i] == 'i') //ok
				len += ft_putnbrbase(va_arg(a, int), 10);
			else if (str[i] == 'u') //ok
				len += ft_putnbrbaselong(va_arg(a, unsigned int), 10, "0123456789"); //ok
			else if (str[i] == 'x') //ok
				len += ft_putnbrbaselong(va_arg(a, unsigned int), 16, "0123456789abcdef"); //ok
			else if (str[i]	== 'X')
				len += ft_putnbrbaselong(va_arg(a, unsigned int), 16, "0123456789ABCDEF"); //ok
			else if (str[i] == '%') //ok
				len += ft_putchar('%');
			else
				return (-1); //ok
		}
		i++;
	}
	va_end (a);
	return (len);
}
/*
int main(void)
{
	//int i = 55;
	int len;
	//void *p = &i;
	
	//len = printf("Hi %s, %% , %s, %c, %d, %x", "He llo", "Hi", 65, -65, i);
	//printf("\n%d", len);
	//ft_printf("Hi %c", 65);
	//printf("%X\n", 464554);
	
	//ft_printf("\n1: %s\n", (char *)NULL);
	//len = ft_printf("2: %s", (char *)NULL);
	
	//ft_printf("\n3: %p\n", (void *)-1);
	//len = printf("3: %p", (void *)-1);
	
	len = printf("%u", 9223372036854775807LL);
	printf("\nlen: %d\n", len);
	len = ft_printf("%u", 9223372036854775807LL);
	printf("\nlen: %d", len);
}*/
//if (c == 'i' || c =='d')
//if (strch(c, "id"))
