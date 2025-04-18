/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_blocks1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:28:27 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:31:08 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*make_number(char nb, int mill);
char	*ft_strstr(char *str, char *to_find);
int		str_len(char *str);
int		print_ext_nb(char *str, int begin, char sep, char *error);
int		cut_str(char *str, int i);
int		is_zero(char *str);

char	handle_separator(int print_space)
{
	if (!print_space)
		return ('\0');
	return (' ');
}

void	block_below_twenty(
		int block_value, int current_block, char *dict, char *error)
{
	char	text[5];
	char	*num;
	char	separator;

	separator = handle_separator(current_block);
	if (block_value < 10 && block_value != 0)
	{
		num = make_number(block_value + '0', 0);
		print_ext_nb(ft_strstr(dict, num), str_len(num), separator, error);
		write(1, " ", 1);
	}
	else
	{
		text[0] = (block_value / 10) + '0';
		text[1] = (block_value % 10) + '0';
		text[2] = ':';
		text[3] = '\0';
		print_ext_nb(ft_strstr(dict, text), str_len(text), separator, error);
		write(1, " ", 1);
	}
}

void	block_of_decimals(
		int block_value, int current_block, char *dict, char *error)
{
	char	*num;
	int		unity;
	int		ten;
	char	separator;

	separator = handle_separator(current_block);
	unity = (block_value % 10);
	ten = (block_value / 10);
	num = make_number(ten + '0', 1);
	print_ext_nb(ft_strstr(dict, num), str_len(num), separator, error);
	write(1, " ", 1);
	free(num);
	if (unity != 0)
	{
		num = make_number(unity + '0', 0);
		print_ext_nb(ft_strstr(dict, num), str_len(num), separator, error);
		write(1, " ", 1);
		free(num);
	}
}

void	block_of_cents(
		int block_value, int current_block, char *dict, char *error)
{
	char	*num;
	int		hundred;
	int		only_decimals;
	char	separator;

	separator = handle_separator(current_block);
	hundred = (block_value / 10) / 10;
	only_decimals = block_value - (hundred * 100);
	num = make_number((hundred) + '0', 0);
	print_ext_nb(ft_strstr(dict, num), str_len(num), separator, error);
	write(1, " ", 1);
	if (only_decimals != 0)
	{
		print_ext_nb(ft_strstr(dict, "100"), 4, separator, error);
		write(1, " ", 1);
	}
	free(num);
	if (only_decimals < 20)
		block_below_twenty(only_decimals, current_block, dict, error);
	else
		block_of_decimals(only_decimals, current_block, dict, error);
}

void	last_block(
	int current_block, int number_of_blocks, char *dict, char *error)
{
	char	*num;
	int		number_of_zeroes_through_block;
	char	separator;

	separator = handle_separator(current_block);
	number_of_zeroes_through_block = (number_of_blocks - current_block - 1) * 3;
	if (current_block + 1 != number_of_blocks)
	{
		num = make_number('1', number_of_zeroes_through_block);
		print_ext_nb(ft_strstr(dict, num), str_len(num), separator, error);
		write(1, " ", 1);
		free(num);
	}
}
