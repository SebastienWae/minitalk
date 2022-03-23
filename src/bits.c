/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:38:38 by seb               #+#    #+#             */
/*   Updated: 2022/03/23 15:27:50 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bytetobits(char b, char bits[8])
{
	unsigned char	shift;

	shift = 0;
	while (shift < 8)
	{
		if ((b << shift) & 128)
			bits[shift] = 1;
		else
			bits[shift] = 0;
		shift++;
	}
}

char	bitstobyte(char bits[8])
{
	char			byte;
	unsigned char	shift;

	byte = 0;
	shift = 0;
	while (shift < 8)
	{
		if (bits[shift])
			byte |= 128 >> shift;
		shift++;
	}
	return (byte);
}
