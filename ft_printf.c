/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:42:36 by mmoramov          #+#    #+#             */
/*   Updated: 2022/10/28 20:47:55 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;
	len = 0;
	
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

int	ft_putnbr(int n)
{
	long	nbr;
	int		len;

	len = 0;
	
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		len = 1;
		ft_putchar(nbr + '0');
	}
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}

/*int ft_putnbrbase(int n, char base)
{
	long	nbr;
	int		len;
	int 	base_len;

	len = 0;
	base_len = ft_strlen(base);

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < base_len)
	{
		len = 1;
		ft_putchar(nbr + '0');
	}
	else
	{
		len += ft_putnbr(nbr / base_len);
		len += ft_putnbr(nbr % base_len);
	}
	return (len);	
}*/

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
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] == 'c')
				len += ft_putchar(va_arg(a, int));
			else if (str[i] == 's')
				len += ft_putstr(va_arg(a, char*));
			else if (str[i] == 'p')
				//TODO
				break;
			else if (str[i] == 'd' || str[i] == 'i')
				len += ft_putnbr(va_arg(a, int));
			else if (str[i] == 'u')
				//TODO
				break;
			else if (str[i] == 'x')
				//TODO
				break;
			else if (str[i]	== 'X')
				//TODO
				break;
			else if (str[i] == '%')
				len += ft_putchar('%');
			else
				return (-1);
		}
		i++;
	}
	va_end (a);
	return (len);
}

int main(void)
{
	int i = 6;
	int len;
	
	len = ft_printf("Hi %s, %% , %s, %c, %d, %i", "He llo", "Hi", 65, -65, 45);
	printf("\n%d", len);
	//ft_printf("Hi %c", 65);
	//printf("%X", 464554);
}

//if (c == 'i' || c =='d')
//if (strch(c, "id"))

