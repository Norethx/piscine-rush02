/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:25:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 16:55:12 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	reverse_str(char *str);

int		num_len(int num);

char	*ft_itoa(int nb)
{
	char	*result;
	int		i;

	result = (char *)malloc(num_len(nb)+1);
	i = 0;
	if (nb == 0)
	{
		result[i] = '0';
		i++;
	}
	while (nb > 0)
	{
		result[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	result[i] = '\0';
	reverse_str(result);
	return (result);
}

int	num_len(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
