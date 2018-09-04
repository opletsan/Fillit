/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_fn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:16:42 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 20:17:41 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strsub(char const *s, int start, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s || !(res = (char*)malloc(sizeof(*res) * len + 1)))
		return (NULL);
	while (i < len && s[start] != '\0')
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return ;
	while (n > i)
	{
		((unsigned char*)s)[i] = '\0';
		i++;
	}
}

void	ft_free(char **array)
{
	size_t i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i++] = NULL;
	}
	free(array);
	array = NULL;
}
