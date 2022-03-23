/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:25 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/23 16:02:41 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>
#include <signal.h>
#include <libft.h>
#include <ft_printf.h>

void	send_bits_to_pid(int pid, char bits[8])
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (bits[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	send_message_to_pid(char *p, char *msg)
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
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		return (send_message_to_pid(argv[1], argv[2]));
	return (0);
}
