/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:17:23 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:13:32 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str);

char	*make_number(char nb, int mill)
{
	char	*str;
	int		i;

	str = (char *)(malloc(mill + 3));
	str[0] = nb;
	i = 0;
	while (++i <= mill)
	{
		str[i] = '0';
	}
	str[i] = '\0';
	return (str);
}

char	*complete_number(char *number)
{
	int		len;
	char	*completed;
	int		i;

	len = str_len(number);
	if ((len % 3) != 0)
	{
		completed = (char *)malloc((len + 1) + (3 - (len % 3)));
		len = 3 - (len % 3);
		i = -1;
		while (++i < len)
			completed[i] = '0';
	}
	else
	{
		completed = (char *)malloc(len + 1);
		len = 0;
	}
	i = -1;
	while (number[++i])
		completed[len + i] = number[i];
	completed[len + i] = '\0';
	return (completed);
}
