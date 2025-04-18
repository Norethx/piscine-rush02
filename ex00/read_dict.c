/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:39:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:31:39 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	write_str(char *dest, char *src);
char	*make_number(char nb, int mill);
char	*ft_strstr(char *str, char *to_find);
char	*ft_itoa(int nb);

char	*read_dict(char *path, int size, char *error)
{
	int		fd;
	ssize_t	bytes_lidos;
	char	*buffer;

	fd = open(path, 0);
	if (fd == -1)
	{
		write_str(error, "Dict Error\n");
		return ((void *)0);
	}
	buffer = (char *)malloc(size);
	bytes_lidos = read(fd, buffer, size - 1);
	if (bytes_lidos == -1)
	{
		write_str(error, "Dict Error\n");
		close(fd);
		free(buffer);
		return ((void *)0);
	}
	buffer[bytes_lidos] = '\0';
	close(fd);
	return (buffer);
}

ssize_t	get_dict_size(char *path, char *error)
{
	int		fd;
	ssize_t	count;
	char	buffer[1];

	fd = open(path, 0);
	if (fd == -1)
	{
		write_str(error, "Dict Error\n");
		return (0);
	}
	count = 0;
	while (read(fd, buffer, 1) > 0)
		count++;
	close(fd);
	return (++count);
}

int	verify_int(char	*dict, int *nb)
{
	char	*nb_str;

	if (*nb <= 100)
	{
		nb_str = ft_itoa(*nb);
		if (ft_strstr(dict, nb_str) == (void *)0)
		{
			free(nb_str);
			return (1);
		}
		free(nb_str);
		if (*nb < 20)
			*nb += 1;
		else
			*nb += 10;
	}
	return (0);
}

int	verify_char(char	*dict, int *number)
{
	int		number_of_zeroes;
	char	*number_in_char;

	number_of_zeroes = 0;
	if (*number > 100)
	{
		number_of_zeroes += 3;
		number_in_char = make_number('1', number_of_zeroes);
		if (ft_strstr(dict, number_in_char) == (void *)0)
		{
			free(number_in_char);
			return (1);
		}
		free(number_in_char);
	}
	return (0);
}

int	verify_dict(char	*dict)
{
	int		dict_line;
	int		number;

	dict_line = -1;
	number = 0;
	while (++dict_line < 40)
	{
		if (verify_int(dict, &number))
			return (1);
		if (verify_char(dict, &number))
			return (1);
	}
	return (0);
}
