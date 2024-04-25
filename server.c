/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/25 18:22:58 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

int	ft_recursive_power(int nbr, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nbr * ft_recursive_power(nbr, power - 1);
		return (res);
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*make_string(char *str, char const letter)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (NULL == new_str)
		return (NULL);
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	i = 0;
	new_str[j++] = letter;
	new_str[j] = '\0';
	free ((void *)(str));
	return (new_str);
}

void	end(char *final, int result, int counter, int len)
{
	final = make_string(final, result);
	if (result == '\0')
	{
		printf("%s\n", final);
		final = NULL;
	}
	counter = 0;
	result = 0;
	len += 1;
}

char	*ft_strdup(const char *s1)
{
	int		lens;
	char	*str;
	int		i;

	i = 0;
	lens = ft_strlen(s1) + 1;
	str = (char *)malloc(lens * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	signal_handler(int signum)
{
	static int	counter = 0;
	static int	result = 0;
	static int	len = 0;
	static char	*final;

	if (!final)
		final = ft_strdup("");
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		end(final, result, counter, len);
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	printf("Welcome to nbidal's server\n");
	printf("Server's PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		sleep(50);
}
