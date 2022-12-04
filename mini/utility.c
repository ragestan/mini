/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:21:45 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/04 10:21:47 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	else if (n < 0)
	{
		i += ft_putchar ('-');
		n = -n;
		i += ft_putnbr (n);
	}
	else if (n > 9)
	{
		i += ft_putnbr (n / 10);
		i += ft_putnbr (n % 10);
	}
	else
	{
		i += ft_putchar (n + 48);
	}
	return (i);
}

int	ft_atoi(char *str)
{
	long long	c;
	int			i;

	i = 1;
	c = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			i = -i;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		c = c * 10 + *str++ - '0';
		if (c * i > 2147483647)
			return (-1);
		if (c * i < -2147483648)
			return (0);
	}
	c = c * i;
	i = c;
	return (i);
}
