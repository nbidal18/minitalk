/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/25 10:58:52 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

int	recursive_power(int 2, int 3)
{
	/*
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		2 ^ 3
		res = 2 * ft_recursive_power(2, 2);
			res = 2 * ft_recursive_power(2, 1);
				res = 2 * ft_recursive_power(2, 0);
		2 *
			2 *
				2 * 1
		return (res);
	}
	*/
}

char	*make_string(char const *s1, char const letter)
{
	/*
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free ((void *)(s1));
	return (tab);
	*/
}

void	signal_handler(int signum)
{
	/*
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
		final = letter_to_string(final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
		len += 1;
	}
	*/
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
