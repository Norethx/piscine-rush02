/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:18:44 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:08:59 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_number(char c);

void	write_str(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	clear_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		str[i] = '\0';
	}
}

void	fill_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] < 50)
	{
		str[i] = c;
	}
	str[i] = '\0';
}

int	str_equal(char *target, char*src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		if (target[i] != src[i])
			return (0);
	}
	if (target[i])
		return (0);
	return (1);
}
