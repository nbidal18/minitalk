/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/08 17:42:48 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_recursive_power(nb, power - 1);
		return (res);
	}
}

char	*letter_to_string(char const *s1, char const letter)
{
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
	tab[j] = '\0';
	free ((void *)(s1));
	return (tab);
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
		result = result + 0; // does this turn it into a char or what bruh *** // I guess result is the result we get once we receive all 8 bits
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - counter)); // what the hell is this
	counter++;
	if (counter == 8)
	{
		final = letter_to_string(final, result); // how come letter_to_string() is going to receive result as a char when it has been declaered as an int? ***
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
		len += 1;
	}
}

int	main(void) // I really need to understand how both this while and this signal_received struct work
{
	struct sigaction	signal_received;

	ft_printf("> nbidal's server\n");
	ft_printf("> PID: %d\n", getpid());
	ft_printf("> Output below...\n");
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
}
