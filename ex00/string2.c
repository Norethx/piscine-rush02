/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:56:12 by brunofer          #+#    #+#             */
/*   Updated: 2025/03/30 22:31:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str);
int	is_number(char c);

char	*str_cat(char *dest, char *src)
{
	int	src_idx;
	int	dest_idx;

	src_idx = -1;
	dest_idx = str_len(dest);
	while (src[++src_idx])
	{
		dest[dest_idx + src_idx] = src[src_idx];
	}
	return (dest);
}

int	cut_str(char *str, int i)
{
	char	part[4];
	int		max;
	int		nbr;
	int		idx;

	idx = -1;
	max = (i * 3) + 3;
	nbr = 0;
	while (((i * 3) + ++idx) < max)
		part[idx] = str[idx + (i * 3)];
	part[3] = '\0';
	idx = -1;
	while (part[++idx] != '\0')
		nbr = (nbr * 10) + (part[idx] - '0');
	return (nbr);
}

void	reverse_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = str_len(str) -1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_strstr(char *dict, char *number)
{
	int		dict_index;
	int		number_index;

	dict_index = -1;
	while (dict[++dict_index])
	{
		if (number[0] == dict[dict_index])
		{
			number_index = 0;
			while (number[number_index]
				&& (number[number_index] == dict[dict_index + number_index]))
				number_index++;
			if (number[number_index] == '\0'
				&& !is_number(dict[dict_index + number_index]))
				return (&dict[dict_index]);
		}
	}
	return ((void *)0);
}
