/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/02 15:57:27 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int server_id, char *message)
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
				kill(server_id, SIGUSR1);
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 1)
				kill(server_id, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(server_id, SIGUSR1);
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

int	main(int argc, char **argv)
{
	char	*message;
	int		server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (server_id == 0)
			printf("[ERROR] Can't copy-paste the PID? bruh.\n");
		message = argv[2];
		if (message[0] == '\0')
			printf("[ERROR] Type something duh.\n");
		if (server_id && message[0])
			send_signals(server_id, message);
	}
	else
	{
		printf("[ERROR] Usage: ./Client 1234 \"hello world\"\n");
	}
	return (0);
}
