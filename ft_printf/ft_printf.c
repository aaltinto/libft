/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:58:08 by aaltinto          #+#    #+#             */
/*   Updated: 2023/07/24 11:58:35 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_flags(char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's' 
			|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i' 
			|| str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X' 
			|| str[i + 1] == '%'));
}

int	ft_conditions(va_list *arg, char c)
{
	if (c == 's')
		return (ft_str(va_arg((*arg), char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg((*arg), unsigned long long int), 1));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg((*arg), int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg((*arg), unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg((*arg), unsigned int), 'a' - 10));
	else if (c == 'X')
		return (ft_hex(va_arg((*arg), unsigned int), 'A' - 10));
	else if (c == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else
		return (ft_putchar(c));
}

int	flag_check(va_list *arg, char *str, int i)
{
	int		error_check;
	int		retval;

	retval = 0;
	while (str[++i])
	{
		if (ft_flags((char *)str, i))
		{
			error_check = ft_conditions(arg, str[++i]);
			if (error_check == -1)
				return (-1);
			retval += error_check;
		}
		else
		{
			retval ++;
			if (ft_putchar(str[i]) == -1)
				return (-1);
		}
	}
	return (retval);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		retval;
	int		i;

	va_start(arg, str);
	i = -1;
	retval = 0;
	retval += flag_check(&arg, (char *)str, i);
	va_end(arg);
	return (retval);
}
