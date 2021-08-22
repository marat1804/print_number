/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:23:22 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 20:48:23 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
typedef struct s_dict
{
	char			*number;
	char			*word;
	struct s_dict	*next;
}	t_dict;

typedef struct s_string
{
	char			*data;
	struct s_string	*next;
}	t_string;

/*---------UTILS---------*/
void	ft_putstr(char *str);
int		ft_print_nbr(t_dict **dict, char *nbr, t_string **res);
char	**ft_split(char *str, char *charset);
int		word_count_in_matrix(char **words);
void	free_matrix(char **words);
char	*ft_strjoin(int size, char **strs, char *sep);

/*------VALIDATORS-------*/
int		ft_valid_number(char *s);
int		get_nbr_list(char *nbr);

/*------PRINT_NUMBER------*/
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
void	ft_list_push_back(t_string **begin_list, char *data);
char	*ft_num_to_str(char c, int i);

/*------DICT_QUERIES------*/
int		dict_rem_0(t_dict **dict, char c, t_string **res, int i);
int		dict_rem_2(t_dict **dict, char c, t_string **res);
int		dict_rem_1(t_dict **dict, char c, char d, t_string **res);
t_dict	**dict_parse(char *filename, int *error);
t_dict	**dict_init(void);
#endif
