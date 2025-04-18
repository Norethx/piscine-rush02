/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:19:09 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:23:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	write_str(char *dest, char *src);
char	*read_dict(char *path, int size, char *error);
int		get_dict_size(char *path, char *error);
char	*complete_number(char *number);
void	handle_blocks_conditions(char *number, char *dict, char *error);
int		verify_dict(char	*dict);

int	number_error(char *number, char *error)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!((number[i] >= '0' && number[i] <= '9')))
		{
			write_str(error, "error");
			return (1);
		}
	}
	return (0);
}

void	from_one_param(char *number, char *error)
{
	int		dict_size;
	char	*dict;
	char	*complete;

	if (number_error(number, error))
		return ;
	dict_size = get_dict_size("numbers.dict", error);
	if (!dict_size)
		return ;
	dict = read_dict("numbers.dict", dict_size, error);
	if (verify_dict(dict))
	{
		write_str(error, "verify_dict");
		return ;
	}
	complete = complete_number(number);
	handle_blocks_conditions(complete, dict, error);
}

void	from_two_param(char *dict_name, char *number, char *error)
{
	int		dict_size;
	char	*dict;
	char	*complete;

	(void)dict;
	if (number_error(number, error))
		return ;
	dict_size = get_dict_size(dict_name, error);
	if (!dict_size)
		return ;
	dict = read_dict(dict_name, dict_size, error);
	complete = complete_number(number);
	handle_blocks_conditions(complete, dict, error);
}
