/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sender.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:48:40 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/22 18:34:58 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_SENDER_H
# define SIGNAL_SENDER_H

int		send_message_to_pid(char *p, char *msg);
void	ctob(char c, int b_msg[8]);

#endif
