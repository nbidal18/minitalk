/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/07 15:55:09 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str) // from my Libft
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

void	send_signals(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i]) // to send zeros and ones with the respective signal until 8 have been sent
	{
		j = -1;
		while (++j < 8)
		{
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 0) // this bugs me a little bit, the "& 1" simply extracts the last bit and compares it 
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[i] >> (7 - j)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	j = 0;
	while (j++ < 8) // to add padding I guess, but why do I reset to 0 just before??
	{
		kill(pid, SIGUSR1);
		usleep(50); // why do we use usleep()? I guess there's also a sleep()??
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid == 0)
		{
			printf("[ERROR] Can't copy paste the PID? bruh.\n");
			return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			printf("[ERROR] How about you insert some text duh.\n");
			return (0);
		}
		send_signals(pid, message);
	}
	else if (argc > 3)
		printf("[ERROR] Too many arguments.\nTry ./client <pid> <message>\n");
	else if (argc < 3)
		printf("[ERROR] Too few arguments.\nTry ./client <pid> <message>\n");
	return (0);
}
