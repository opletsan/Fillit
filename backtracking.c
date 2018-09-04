/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:24:46 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 20:25:38 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_add_tetrim(char **map, t_fill *lst, int i, int j)
{
	int	x;

	x = 0;
	map[i][j] = lst->tetrim[lst->koord[x][0]][lst->koord[x][1]];
	while (x++ < 3)
	{
		map[i += lst->koord[x][0] - lst->koord[x - 1][0]]
			[j += lst->koord[x][1] - lst->koord[x - 1][1]] =
			lst->tetrim[lst->koord[x][0]][lst->koord[x][1]];
	}
}

int		ft_check_map(char **map, t_fill *lst, int i, int j)
{
	int x;
	int x_x;
	int y_y;
	int	suc;

	x = 0;
	suc = 0;
	if (map[i] == NULL)
		return (1);
	suc += (map[i][j] == '.');
	while (x++ < 3)
	{
		x_x = (lst->koord[x][0] - lst->koord[x - 1][0]);
		y_y = (lst->koord[x][1] - lst->koord[x - 1][1]);
		suc += (j + y_y >= 0 &&
				map[i + x_x] != NULL &&
				map[i][j + y_y] != '\0' &&
				map[i += x_x][j += y_y] == '.');
	}
	if (suc != 4)
		return (1);
	return (0);
}

int		ft_check_next(char **map, t_fill *lst, int i, int j)
{
	if (ft_check_map(map, lst, i, j) == 0)
	{
		ft_add_tetrim(map, lst, i, j);
		return (0);
	}
	return (1);
}

void	ft_del_tetrim(char **map, t_fill *lst, int i, int j)
{
	int x;

	x = 0;
	map[i][j] = '.';
	while (x++ < 3)
	{
		map[i += lst->koord[x][0] - lst->koord[x - 1][0]]
			[j += lst->koord[x][1] - lst->koord[x - 1][1]] = '.';
	}
}

int		ft_backtracking(char **map, t_fill *lst, int i, int j)
{
	int f;

	f = 0;
	while (map && map[i] && lst)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (ft_check_next(map, lst, i, j) == 0)
			{
				f = 1;
				if (ft_backtracking(map, lst->next, 0, -1) == 1)
				{
					f = 0;
					ft_del_tetrim(map, lst, i, j);
				}
				else
					return (0);
			}
		}
		i++;
	}
	if (lst && f == 0)
		return (1);
	return (0);
}
