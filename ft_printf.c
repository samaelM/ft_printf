/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemaldo <maemaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:01 by maemaldo          #+#    #+#             */
/*   Updated: 2024/01/11 14:49:55 by maemaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ltoa_hexa_size(unsigned long long nb)
{
	int	nlen;

	nlen = 0;
	if (nb < 0)
	{
		nlen = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 16;
		nlen++;
	}
	return (nlen);
}

char	*ft_ltoa_hexa(unsigned long long n, char format)
{
	size_t				nlen;
	char				*res;
	unsigned long long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	nlen = ft_ltoa_hexa_size(num);
	res = ft_calloc((nlen + 1) * sizeof(char), 1);
	res[nlen--] = '\0';
	if (n < 0)
	{
		0 [res] = '-';
		num = -num;
	}
	while (nlen >= 0 && num > 0)
	{
		res[nlen] = "0123456789abcdef"[(num % 16)];
		if (format == 'X' && (res[nlen] >= 'a' && res[nlen] <= 'f'))
			res[nlen] -= 32;
		num /= 16;
		nlen--;
	}
	return (res);
}

int	ft_utoa_size(long nb)
{
	int	nlen;

	nlen = 0;
	if (nb < 0)
	{
		nlen = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nlen;
	long			num;
	char			*res;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	nlen = ft_utoa_size(num);
	res = malloc((nlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[nlen--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (nlen >= 0 && num > 0)
	{
		res[nlen--] = '0' + (num % 10);
		num /= 10;
	}
	return (res);
}

char	*printf_s(const char *src)
{
	char	*dest;

	if (src == NULL)
		dest = ft_strdup("(null)");
	else
		dest = ft_strdup(src);
	return (dest);
}

char	*printf_p(long n)
{
	char	*dest;
	char	*last;

	if (n == 0)
		return (ft_strdup("(nil)"));
	last = ft_ltoa_hexa(n, 'x');
	dest = ft_strjoin("0x", last);
	free(last);
	return (dest);
}

void	ft_put_and_free(char *argc, int *len)
{
	ft_putstr_fd(argc, 1);
	*len += ft_strlen((const char *)argc);
	free(argc);
}

int	ft_get_str(const char *format, int i, int *len, va_list *ap)
{
	char	*argc;

	argc = NULL;
	if (format[i + 1] == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		(*len)++;
	}
	else if (format[i + 1] == '%')
		argc = ft_strdup("%");
	else if (format[i + 1] == 's')
		argc = printf_s(va_arg(*ap, const char *));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		argc = ft_ltoa_hexa(va_arg(*ap, unsigned int), format[i + 1]);
	else if (format[i + 1] == 'p')
		argc = printf_p(va_arg(*ap, unsigned long long));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		argc = ft_itoa(va_arg(*ap, int));
	else if (format[i + 1] == 'u')
		argc = ft_utoa(va_arg(*ap, unsigned int));
	else
		return (0);
	if (argc)
		ft_put_and_free(argc, len);
	return (1);
}

void	ft_putlen(const char *c, int i, int *len)
{
	write(1, &c[i], 1);
	(*len)++;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	if (format == 0)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!ft_get_str(format, i, &len, &ap))
				return (-1);
			i++;
		}
		else
			ft_putlen(format, i, &len);
		i++;
	}
	va_end(ap);
	return (len);
}
//  void main(void)
//  {
// 	int a, b;
// 	char	c = 'a';
// 	a = ft_printf("%cqwerty", c);
// 	printf("\n");
// 	b = printf("%cqwerty", c);
// 	printf("\n");
// 	printf("%d - %d", a, b);
//  }