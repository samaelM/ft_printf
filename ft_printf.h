/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maemaldo <maemaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:57:39 by maemaldo          #+#    #+#             */
/*   Updated: 2024/04/19 18:30:48 by maemaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *txt, ...);
int		ft_ltoa_hexa_size(unsigned long long nb);
char	*ft_ltoa_hexa(unsigned long long n, char format);
int		ft_utoa_size(long nb);
char	*ft_utoa(unsigned int n);
char	*printf_s(const char *src);
char	*printf_p(long n);
void	ft_put_and_free(char *argc, int *len);
void	ft_putlen(const char *c, int i, int *len);
int		ft_putstr_fd2(char *s, int fd);
void	ft_printc(char c, int fd, int *len);
int		ft_putchar_fd2(char c, int fd);

#endif