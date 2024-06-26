/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/10 16:13:17 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = -1;
		while (++j < 8)
		{
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[i] >> (7 - j)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			ft_printf("[ERROR] Can't copy paste the PID? bruh.\n");
			return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			ft_printf("[ERROR] How about you insert some text duh.\n");
			return (0);
		}
		send_signals(pid, message);
	}
	else if (argc > 3)
		ft_printf("[ERROR] Too many arguments.\n./client <pid> <message>\n");
	else if (argc < 3)
		ft_printf("[ERROR] Too few arguments.\n./client <pid> <message>\n");
	return (0);
}
