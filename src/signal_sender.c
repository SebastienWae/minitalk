/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:47:47 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/22 18:43:37 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal_sender.h>
#include <signal.h>
#include <libft.h>
#include <ft_printf.h>

void	ctob(char c, int b_msg[8])
{
	int	i;

	i = 7;
	while (c)
	{
		b_msg[i] = c % 2;
		c = c / 2;
		i--;
	}
	b_msg[i] = c % 2;
}

int	send_message_to_pid(char *p, char *msg)
{
	int	i;
	int	pid;
	int	binary_msg[8];

	pid = ft_atoi(p);
	ft_printf("pid: %d\n", pid);
	while (*msg)
	{
		i = 0;
		ctob(*msg, binary_msg);
		while (i < 8)
		{
			if (binary_msg[i])
				ft_printf("1");
			else
				ft_printf("0");
			i++;
		}
		ft_printf("\n");
		msg++;
	}
	return (0);
}
