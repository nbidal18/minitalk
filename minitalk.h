/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:13 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/08 17:42:44 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_recursive_power(int nb, int power);
char	*letter_to_string(char const *s1, char const letter);
void	signal_handler(int signum);
void	send_signals(int pid, char *message);

#endif
