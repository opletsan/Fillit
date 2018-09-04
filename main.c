/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:25:54 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 20:26:48 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size_map(char *input)
{
	int	x;
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (input[i])
	{
		if (input[i] == '#')
			size++;
		i++;
	}
	x = 2;
	while (x * x < size)
		x++;
	return (x);
}

char	**ft_create_map(int x)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	while (j < x)
	{
		i = 0;
		if (!(map[j] = (char*)malloc(sizeof(char) * (x + 1))))
		{
			ft_free(map);
			return (NULL);
		}
		while (i < x)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**ft_algorithm(char *input, t_fill *begin)
{
	int		n;
	char	**map;

	n = ft_size_map(input);
	map = ft_create_map(n);
	while (ft_backtracking(map, begin, 0, -1) == 1)
	{
		ft_free(map);
		map = ft_create_map(++n);
	}
	return (map);
}

int		main(int argc, char **argv)
{
	t_fill	*begin;
	char	*buf;
	char	**map;
	int		i;

	i = -1;
	if (argc != 2)
	{
		write(1, "usage: fillit target_file\n", 26);
		return (0);
	}
	if ((buf = ft_validation(argv[1])) &&
			(begin = ft_create_lst(buf)) &&
			(map = ft_algorithm(buf, begin)))
	{
		while (map[++i])
		{
			write(1, map[i], ft_strlen(map[i]));
			write(1, "\n", 1);
		}
		ft_free(map);
		ft_free_lst(begin);
	}
	return (0);
}
