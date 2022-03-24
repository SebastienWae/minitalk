/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:54 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/24 14:32:49 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>
#include <ft_printf.h>
#include <libft.h>
#include <signal.h>
#include <unistd.h>
#include <utils.h>

void	print_message(char c)
{
	static char	*str;
	char		*tmp;

	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return ;
	}
	if (!c)
	{
		ft_printf("%s", str);
		free(str);
		str = NULL;
	}
	else
	{
		tmp = str;
		str = ft_strappend_c(str, c);
		free(tmp);
	}
}

void	sigsur_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	i;
	static char				*bits;
	static int				pid;
	char					c;

	(void)context;
	if (!bits)
	{
		bits = ft_calloc(8, sizeof(char));
		if (!bits)
			return ;
	}
	pid = info->si_pid;
	if (signum == SIGUSR1)
		bits[i] = 1;
	if (++i == 8)
	{
		i = 0;
		c = bitstobyte(bits);
		free(bits);
		bits = NULL;
		print_message(c);
		if (!c)
			kill(pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	pid = getpid();
	ft_printf("%d\n", pid);
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
