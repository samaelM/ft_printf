/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemaldo <maemaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:01 by maemaldo          #+#    #+#             */
/*   Updated: 2024/04/23 13:16:24 by maemaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_p(long n)
{
	char	*dest;
	char	*last;

	if (n == 0)
		return (ft_strdup("(nil)"));
	last = ft_ltoa_hexa(n, 'x');
	if (!last)
		return (NULL);
	dest = ft_strjoin("0x", last);
	if (!dest)
		return (NULL);
	free(last);
	return (dest);
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

void	ft_printc(char c, int fd, int *len)
{
	if (ft_putchar_fd2(c, fd) != -1 && *len >= 0)
		(*len)++;
	else
		(*len) = -1;
}

int	ft_putstr_fd2(char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (-1);
	i = 0;
	len = ft_strlen(s);
	len = write(fd, s, len);
	return (len);
}

void	ft_putlen(const char *c, int i, int *len)
{
	if (write(1, &c[i], 1) == -1)
		(*len) = -1;
	else if (len >= 0)
		(*len)++;
}
