/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:15:21 by aaltinto          #+#    #+#             */
/*   Updated: 2023/07/24 12:15:24 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long n, int check)
{
	int	ret;

	ret = 0;
	if (check == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		ret += 2;
		check = 0;
	}
	if (n >= 16)
		ret += ft_pointer(n / 16, 0);
	if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_str(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[++i])
		if (write(1, &s[i], 1) == -1)
			return (-1);
	return (i);
}

int	ft_int(int nb)
{
	long	n;
	int		i;
	int		tmp;

	i = 0;
	n = nb;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		i++;
	}
	if (n > 9)
	{
		tmp = ft_int(n / 10);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	if (ft_putchar(n % 10 + 48) == -1)
		return (-1);
	return (++i);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;
	int	tmp;

	i = 0;
	if (nb > 9)
	{
		tmp = ft_putnbr_unsigned(nb / 10);
		if (tmp == -1)
			return (-1);
		i += tmp + 1;
		if (ft_putnbr_unsigned(nb % 10) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(nb + 48) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned long n, char c)
{
	int	i;
	int	tmp;

	i = 0;
	if (n > 15)
	{
		tmp = ft_hex(n / 16, c);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	if (n % 16 < 10)
	{
		if (ft_putchar((n % 16) + '0') == -1)
			return (-1);
	}
	else if (ft_putchar((n % 16) + c) == -1)
		return (-1);
	return (++i);
}
