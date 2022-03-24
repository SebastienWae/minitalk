/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:30:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/24 14:32:29 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strappend_c(char *src, char c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(src) + 2));
	i = 0;
	while (*src)
		str[i++] = *src++;
	str[i++] = c;
	str[i] = 0;
	return (str);
}
