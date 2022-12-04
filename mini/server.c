/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:21:32 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/04 10:21:36 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static char	c = 0;
	static int	i = 0;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar(c);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR2, &handler);
	signal(SIGUSR1, &handler);
	while (1)
		pause();
	return (0);
}
