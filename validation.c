/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:21:04 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 20:22:01 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*isrc;

	len = 0;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	isrc = (char*)malloc(sizeof(*isrc) * len + 1);
	if (!isrc)
		return (NULL);
	i = 0;
	while (i < len)
	{
		isrc[i] = src[i];
		i++;
	}
	isrc[i] = '\0';
	return (isrc);
}

int		ft_third_valid(char *input, int j)
{
	int		i;
	int		res;
	char	*tetrim;

	while (j < ft_strlen(input))
	{
		i = -1;
		res = 0;
		tetrim = ft_strsub(input, j, 20);
		while (tetrim[++i] != '\0')
		{
			if (tetrim[i] == '#')
			{
				res += ((i - 5) >= 0 && tetrim[i - 5] == '#');
				res += ((i + 5) <= ft_strlen(tetrim) && tetrim[i + 5] == '#');
				res += ((i - 1) >= 0 && tetrim[i - 1] == '#');
				res += ((i + 1) <= ft_strlen(tetrim) && tetrim[i + 1] == '#');
			}
		}
		if (res != 6 && res != 8)
			return (1);
		j += 21;
	}
	return (0);
}

int		ft_second_valid(char *input, int f)
{
	static int	i;
	static int	x;

	if (!i || !x)
	{
		i = 4;
		x = 20;
	}
	while (i < ft_strlen(input))
	{
		if (input[i] != '\n')
			return (1);
		if (i == x + f && input[++i] != '\0')
		{
			if (input[i] != '\n')
				return (1);
			i += 5;
			x += 20;
			ft_second_valid(input, ++f);
		}
		else if (--i != x + f && input[++i] == '\0')
			return (1);
		i += 5;
	}
	return (0);
}

int		ft_first_valid(char *input, int i, int j, int x)
{
	int hash;
	int	point;

	hash = 0;
	point = 0;
	while (input[i])
	{
		if (input[i] != '.' && input[i] != '#' && input[i] != '\n')
			return (1);
		if ((input[i + 1] == '\n' && input[i] == '\n') || input[i + 1] == '\0')
		{
			x++;
			j = i + 1;
			while (--j > (-1) && (input[j] != '\n' || input[j - 1] != '\n'))
			{
				hash += (input[j] == '#');
				point += (input[j] == '.');
			}
		}
		i++;
	}
	if (x > 26 || hash != 4 * x || point != 12 * x || input[i - 1] != '\n')
		return (1);
	return (0);
}

char	*ft_validation(char *file)
{
	char	buf[600];
	int		fd;
	int		res;
	char	*input;

	if (((fd = open(file, O_RDONLY)) == -1) ||
			((res = read(fd, buf, 600)) == -1) ||
			((close(fd)) == -1))
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	buf[res] = '\0';
	input = ft_strdup(buf);
	if (!*input || (ft_first_valid(input, 0, 0, 0) == 1) ||
		(ft_second_valid(input, -1) == 1) || (ft_third_valid(input, 0) == 1))
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	return (input);
}
