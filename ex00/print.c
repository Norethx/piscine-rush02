/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:00:11 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:12:38 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	write_str(char *dest, char *src);
int		is_alpha(char c);

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}

void	print_number(int number)
{
	char	nb;

	if (number > 9)
		print_number(number / 10);
	nb = ((number % 10) + '0');
	write(1, &nb, 1);
}

int	is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((!((str[i] >= 32 && str[i] <= 125) || (str[i] == '\n'))))
			return (0);
	}
	return (1);
}

void	print_ext_nb_loop(char *str, int reach_colon, int reach_content)
{
	int	i;

	i = 0;
	while (!(str[++i] < 32))
	{
		if (str[i] == ':' && !reach_colon)
		{
			reach_colon = 1;
			i++;
		}
		if ((!(str[i] < 32)) && reach_colon && !reach_content)
		{
			reach_content = 1;
			i++;
		}
		if (reach_colon && reach_content)
			write(1, &str[i], 1);
	}
}

int	print_ext_nb(char *str, int begin, char sep, char *error)
{
	int	reach_colon;
	int	reach_content;

	reach_colon = 0;
	reach_content = 0;
	(void)sep;
	(void)begin;
	if (str == (void *)0)
	{
		write_str(error, "Dict Error\n");
		return (1);
	}
	print_ext_nb_loop(str, reach_colon, reach_content);
	return (0);
}
