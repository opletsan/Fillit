/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opletsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:02:40 by opletsan          #+#    #+#             */
/*   Updated: 2018/02/21 21:00:26 by opletsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_fill
{
	char			**tetrim;
	int				koord[4][2];
	struct s_fill	*next;
}					t_fill;

int					ft_strlen(const char *str);
char				*ft_strsub(char const *s, int start, int len);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_free(char **array);

size_t				ft_numline(char const *s, char c);
size_t				ft_numlett(char const *s, unsigned int i, char c);
char				**ft_strsplit(char const *s, char c);

char				*ft_strdup(const char *src);
int					ft_third_valid(char *input, int j);
int					ft_second_valid(char *input, int f);
int					ft_first_valid(char *input, int i, int j, int x);
char				*ft_validation(char *file);

void				ft_free_lst(t_fill *begin);
t_fill				*ft_new_lst(char *tmp);
t_fill				*ft_lstsplit(char *str);
void				ft_subhash(t_fill *lst, char a);
t_fill				*ft_create_lst(char *str);

void				ft_add_tetrim(char **map, t_fill *lst, int i, int j);
int					ft_check_map(char **map, t_fill *lst, int i, int j);
int					ft_check_next(char **map, t_fill *lst, int i, int j);
void				ft_del_tetrim(char **map, t_fill *lst, int i, int j);
int					ft_backtracking(char **map, t_fill *lst, int i, int j);

int					ft_size_map(char *input);
char				**ft_create_map(int x);
char				**ft_algorithm(char *input, t_fill *begin);
int					main(int argc, char **argv);

#endif
