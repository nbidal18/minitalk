/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/03 17:28:13 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

int	

char	*letter_to_string(char const *str, char const result)
{
	int		i;
	int		j;
	char	*tmp_str;

	i = 0;
	j = 0;
	tmp_str = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (tmp_str == NULL)
		return (NULL);
	i = 0;
	tmp_str[j++] = result;
	tmp_str[j] = '\0';
	free ((void *)(str));
	return (tmp_str);
}

void	signal_handler(int signum)
{
	static int	i; // why are these static?
	static int	result;
	static int	len;
	static char	*str;

	i = 0;
	result = 0;
	len = 0;
	if (str == NULL)
		str = ft_strdup("");
	if (signum == SIGUSR1)
		result = result + 0; // does this turn it into a char or what bruh *** // I guess result is the result we get once we receive all 8 bits
	else if (signum == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - i)); // what the hell is this
	i++;
	if (i == 8)
	{
		str = letter_to_string(str, result); // how come letter_to_string() is going to receive result as a char when it has been declaered as an int? ***
		if (result == '\0')
		{
			printf("%s\n", str);
			str = NULL;
		}
		i = 0;
		result = 0;
		len += 1;
	}
}

int	main(void) // I really need to understand how both this while and this signal_received struct work
{
	struct sigaction	signal_received;
	
	printf("--> nbidal's server\n");
	printf("--> PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
}
