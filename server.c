/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:45:55 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/24 16:56:17 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

int	main(void)
{
	struct sigaction	signal_received;

	printf("Welcome to nbidal's server\n");
	printf("Server's PID: %d\n", getpid());
	signal_received.sa_handler = signal_handler;
}
