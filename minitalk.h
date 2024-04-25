/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:13 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/25 10:33:30 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --------------- IMPORTANT (NOTES / TO-DOS) --------------- //

// * need to use ft_printf() instead of printf()

// ------------------- CODE ------------------- //

// client writes, text is converted to bits, sent with signals,
// server receives, converts bits to text and prints
// ./a.out  <PID>  <message>
// argv[0] argv[1]  argv[2]

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif
