/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:15:00 by aaltinto          #+#    #+#             */
/*   Updated: 2023/07/22 18:16:27 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	ft_pointer(unsigned long n, int check);
int	ft_str(char *s);
int	ft_int(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_hex(unsigned long n, char c);
#endif
