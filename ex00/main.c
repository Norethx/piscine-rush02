/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:14:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 19:50:51 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	from_one_param(char *str, char *error);
void	from_two_param(char *dict, char *str, char *error);
void	print_error(char *error);
void	clear_str(char *str);
void	fill_str(char *str, char c);

int	main(int argc, char **argv)
{
	char	error[50];

	error[0] = '\0';
	if (argc == 2)
	{
		from_one_param(argv[1], error);
	}
	else if (argc == 3)
	{
		from_two_param(argv[1], argv[2], error);
	}
	else if (argc > 3 || argc < 2)
	{
		print_error("Error\n");
	}
	print_error(error);
	return (0);
}
