/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:23:22 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 12:23:24 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dict
{
	char	*number;
	char	*word;
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

/*------VALIDATORS-------*/
int		ft_valid_number(char *s);

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
#endif
