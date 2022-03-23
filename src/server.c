/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:54 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/23 16:13:45 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <bits.h>
#include <unistd.h>
#include <signal.h>

void	sigsur_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	i;
	static char				bits[8];

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		bits[i] = 1;
	if (signum == SIGUSR2)
		bits[i] = 0;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		i++;
		if (i == 8)
		{
			ft_printf("%c", bitstobyte(bits));
			i = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = sigsur_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
}
