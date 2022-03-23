/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:25 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/23 20:44:23 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>
#include <ft_printf.h>
#include <libft.h>
#include <signal.h>

char	g_waiting = 0;

void	send_bits_to_pid(int pid, char bits[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_waiting = 1;
		if (bits[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_waiting)
			pause();
		i++;
	}
}

void	send_message_to_pid(char *p, char *msg)
{
	int		pid;
	char	bits[8];

	pid = ft_atoi(p);
	while (*msg)
	{
		bytetobits(*msg, bits);
		send_bits_to_pid(pid, bits);
		msg++;
	}
	bytetobits(*msg, bits);
	send_bits_to_pid(pid, bits);
}

void	sigsur_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("OK\n");
		exit(0);
	}
	if (signum == SIGUSR2)
		g_waiting = 0;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, sigsur_handler);
		signal(SIGUSR2, sigsur_handler);
		send_message_to_pid(argv[1], argv[2]);
		while (1)
			pause();
	}
}
