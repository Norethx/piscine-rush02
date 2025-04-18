/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:59:49 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 20:45:32 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_space(char c)
{
	return (c == ' ');
}

int	is_zero(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '0')
			return (0);
	}
	return (1);
}
