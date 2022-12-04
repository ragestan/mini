/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:20:50 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/04 10:20:57 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	last(int i)
{
	int	j;

	j = 8;
	while (j--)
	{	
		kill (i, SIGUSR2);
		usleep (50);
	}
}

static void	string(int pid, char *str)
{
	int	bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			if ((*str >> bit) & 1)
			{	
				if (kill(pid, SIGUSR1) == -1)
					exit(0);
			}
			else if (*str)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(0);
			}
			usleep(150);
		}
		str++;
	}
}

int	main(int ai, char *ac[])
{
	int		pid;
	char	*str;

	if (ai != 3 || ft_strlen(ac[2]) == 0)
	{
		ft_putstr("./client PID_SERVEUR STRING_TO_PASS\n");
		exit (1);
	}
	pid = ft_atoi(ac[1]);
	str = ac[2];
	string(pid, str);
	last(pid);
	return (0);
}
