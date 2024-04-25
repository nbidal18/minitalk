/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/25 18:16:24 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
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
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (result * sign);
	return (result);
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		server_pid = atoi(argv[1]);
		if (server_pid == 0)
		{
			printf("[ERROR] Wrong PID.\n");
			return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			printf("[ERROR] Insert some text.\n");
			return (0);
		}
		send_signals(server_pid, message);
	}
	else if (argc > 3)
		printf("[ERROR] Too many arguments.\ntry: ./client <pid> <message>\n");
	else if (argc < 3)
		printf("[ERROR] Too few arguments.\ntry: ./client <pid> <message>\n");
	return (0);
}
