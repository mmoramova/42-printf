/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:42:36 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:36 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr((char *)"(null)"));
	return (write(1, s, ft_strlen(s)));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char) c))
		s++;
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

int	ft_putptr(void *p)
{
	int	len;
	int	counter;

	len = 0;
	counter = 0;
	len = ft_putstr((char *)"0x");
	if (len == -1)
		return (-1);
	len += ft_putnbrbase((unsigned long)p, 'p');
	return (len);
}

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

/*int main(void)
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
	
	len = printf("\001\002\007\v\010\f\r\n");
	printf("\nlen: %d\n", len);
	len = ft_printf("\001\002\007\v\010\f\r\n");
	printf("\nlen: %d", len);
}*/
