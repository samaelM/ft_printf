/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemaldo <maemaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:47 by maemaldo          #+#    #+#             */
/*   Updated: 2024/04/23 13:26:53 by maemaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (n == 0)
		return (ft_strdup("0"));
	nlen = ft_ltoa_hexa_size(n);
	res = ft_calloc((nlen + 1) * sizeof(char), 1);
	if (!res)
		return (NULL);
	res[nlen--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (nlen >= 0 && n > 0)
	{
		res[nlen] = "0123456789abcdef"[(n % 16)];
		if (format == 'X' && (res[nlen] >= 'a' && res[nlen] <= 'f'))
			res[nlen] -= 32;
		n /= 16;
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
