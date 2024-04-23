/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/23 17:19:17 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --------------------------- LIBRARIES --------------------------- //

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// --------------------------- TESTING --------------------------- //

// make a program which stays open and closes when I press ctrl + c

/* SERVER TESTING
void signal_handler(int signum) 
{
	printf("\nReceived SIGINT!\n");
	exit(0);
}

int main() 
{
	int i = 0;
	pid_t pid = getpid();

	printf("Program started with PID: %d\n", pid);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	while (1)
	{
		i++;
	}
	return 0;
}
*/

// --------------------------- ACTUAL CODE --------------------------- //

// client writes, text is converted to bits, sent with signals,
// server receives, converts bits to text and prints
// ./a.out  <PID>  <message>
// argv[0] argv[1]  argv[2]

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

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;
	char	key;

	// get the PID
	pid = atoi(argv[1]);
	// get the string inside of  str message
	message = argv[2];
	copy(argv[2], message);
	// here I succesfully have both the PID and the message
	key = 'A'; // takes the first letter of the message
	printf("Original PID: %s\n", argv[1]);
	printf("My PID: %d\n", pid);
	printf("Original message: %s\n", argv[2]);
	printf("My message: %s\n", message);
	encrypt_message(message, key);
	printf("Encrypted message: %s\n", message);
	decrypt_message(message, key);
	printf("Decrypted message: %s\n", message);
	printf("Encryption key: %c\n", key);
}
