/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:40:23 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 19:54:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str);
void	print_str(char *str);
void	clear_str(char *str);
int		is_printable(char *str);

void	print_error(char *error)
{
	if (is_printable(error) && str_len(error))
		print_str(error);
	clear_str(error);
}
