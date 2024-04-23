/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/23 18:05:39 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --------------- LIBRARIES (TO REMOVE) --------------- //

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// --------------- IMPORTANT (NOTES / TO-DOS) --------------- //

// * need to use ft_printf() instead of printf()

// ------------------- CODE ------------------- //

// client writes, text is converted to bits, sent with signals,
// server receives, converts bits to text and prints
// ./a.out  <PID>  <message>
// argv[0] argv[1]  argv[2]

void	send_signals(int pid, char *message)
{
	
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

void	encrypt_message(char *message, char key)
{
	int	i;
	int	len;

	len = 0;
	while (message[len] != '\0')
		len++;

	i = 0;
	while (i < len)
	{
		message[i] = message[i] ^ key;
		i++;
	}
}

void	decrypt_message(char *message, char key)
{
	encrypt_message(message, key);
}

void	copy(char *source, char *dest)
{
	int	i;

	i = 0;
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}

/* TO PUT SOMEWHERE ELSE, WAS IN MAIN()
char	key;

copy(argv[2], message);
key = 'A';
encrypt_message(message, key);
*/

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc == 3)
	{
		server_pid = atoi(argv[1]);
		if (server_pid == NULL)
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
