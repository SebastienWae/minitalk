/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:25 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/22 18:33:29 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <signal_sender.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		return (send_message_to_pid(argv[1], argv[2]));
	return (0);
}
