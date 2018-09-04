/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:23:13 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 20:24:21 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_lst(t_fill *begin)
{
	t_fill	*tmp;

	if (!begin)
		return ;
	while (begin)
	{
		tmp = begin->next;
		ft_free(begin->tetrim);
		free(begin);
		begin = tmp;
	}
	begin = NULL;
}

t_fill	*ft_new_lst(char *tmp)
{
	t_fill	*lst;

	if (!tmp)
		return (NULL);
	if (!(lst = (t_fill*)malloc(sizeof(t_fill))))
	{
		ft_free_lst(lst);
		return (NULL);
	}
	lst->tetrim = ft_strsplit(tmp, '\n');
	lst->next = NULL;
	return (lst);
}

t_fill	*ft_lstsplit(char *str)
{
	t_fill	*lst;
	t_fill	*begin;
	char	tmp[21];

	ft_strncpy(tmp, str, 20);
	tmp[20] = '\0';
	str += 20;
	if (!(lst = ft_new_lst(tmp)))
		return (NULL);
	begin = lst;
	while (*str++)
	{
		ft_bzero(tmp, 20);
		ft_strncpy(tmp, str, 20);
		tmp[20] = '\0';
		if (!(lst->next = ft_new_lst(tmp)))
		{
			ft_free_lst(begin);
			return (NULL);
		}
		lst = lst->next;
		str += 20;
	}
	return (begin);
}

void	ft_subhash(t_fill *lst, char a)
{
	int	i;
	int	j;
	int x;

	x = 0;
	i = 0;
	while (lst->tetrim[i])
	{
		j = 0;
		while (lst->tetrim[i][j])
		{
			if (lst->tetrim[i][j] == '#')
			{
				lst->koord[x][0] = i;
				lst->koord[x++][1] = j;
				lst->tetrim[i][j] = a;
			}
			j++;
		}
		i++;
	}
}

t_fill	*ft_create_lst(char *str)
{
	t_fill	*lst;
	t_fill	*begin;
	char	a;

	if (!(begin = ft_lstsplit(str)))
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	lst = begin;
	a = 'A';
	while (lst)
	{
		ft_subhash(lst, a);
		lst = lst->next;
		a++;
	}
	return (begin);
}
