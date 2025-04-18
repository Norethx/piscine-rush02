/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_blocks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:14 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:31:20 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str);
int		cut_str(char *str, int i);
int		is_zero(char *str);
int		print_ext_nb(char *str, int begin, char sep, char *error);
char	*ft_strstr(char *dict, char *number);

char	handle_separator(int print_space);
void	block_below_twenty(
			int block_value, int current_block, char *dict, char *error);
void	block_of_decimals(
			int block_value, int current_block, char *dict, char *error);
void	block_of_cents(
			int block_value, int current_block, char *dict, char *error);
void	last_block(
			int current_block, int number_of_blocks, char *dict, char *error);

void	handle_blocks(char *number, char *dict, char *error)
{
	int		block_value;
	int		number_of_blocks;
	int		current_block;

	number_of_blocks = str_len(number) / 3;
	current_block = -1;
	block_value = 0;
	while (++current_block < number_of_blocks)
	{
		block_value = cut_str(number, current_block);
		if (!block_value)
			continue ;
		if (block_value >= 0)
		{
			if (block_value < 20)
				block_below_twenty(block_value, current_block, dict, error);
			else if (block_value < 100)
				block_of_decimals(block_value, current_block, dict, error);
			else if (block_value >= 100)
				block_of_cents(block_value, current_block, dict, error);
			last_block(current_block, number_of_blocks, dict, error);
		}
	}
	free(number);
	free(dict);
}

void	handle_blocks_conditions(char *number, char *dict, char *error)
{
	if (is_zero(number))
	{
		print_ext_nb(ft_strstr(dict, "0"), 0, ' ', error);
		return ;
	}
	handle_blocks(number, dict, error);
}
