/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:50:46 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 14:54:04 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_num(char *str, char **num)
{
	char	**words;
	char	*tmp;
	int		i;

	words = ft_split(str, " ");
	if (word_count_in_matrix(words) != 1)
	{
		free_matrix(words);
		return (0);
	}
	tmp = words[0];
	i = 0;
	while (tmp[i] >= '0' && tmp[i] <= '9')
		i++;
	if (i == 0)
		tmp[i++] = '0';
	tmp[i] = '\0';
	*num = ft_strdup(tmp);
	*num = trim_leading_zeros(*num, 1);
	free_matrix(words);
	return (1);
}

int	parse_word(char *str, char **word)
{
	char	**words;

	words = ft_split(str, " ");
	if (word_count_in_matrix(words) == 0)
	{
		free_matrix(words);
		return (0);
	}
	*word = ft_strjoin(word_count_in_matrix(words), words, " ");
	free_matrix(words);
	return (1);
}

int	parse_one_line(t_dict **dict, char *str)
{
	int		flag_num;
	char	**lines;
	char	*num;
	char	*word;
	int		flag_word;

	if (all_space(str))
		return (2);
	if (!replace_first_colon(str))
		return (0);
	lines = ft_split(str, "\n");
	flag_num = parse_num(lines[0], &num);
	flag_word = parse_word(lines[1], &word);
	free_matrix(lines);
	if (flag_num && flag_word)
	{
		flag_num = get_nbr_list(num);
		if (dict_find_elem(dict, flag_num, num) != -1)
			return (0);
		dict_push_elem(dict, flag_num, num, word);
		return (1);
	}
	return (free_word_num(word, num, flag_num, flag_word));
}

t_dict	**parse_lines(char **lines)
{
	t_dict	**dict;
	int		flag;

	dict = dict_init();
	while (*lines != NULL)
	{
		flag = parse_one_line(dict, *lines);
		if (flag == 0)
		{
			free_dict(dict);
			return (NULL);
		}
		lines++;
	}
	return (dict);
}

t_dict	**dict_parse(char *filename)
{
	t_dict	**dict;
	char	**lines;
	int		error;

	error = 0;
	lines = get_lines(filename, &error);
	if (error)
		return (NULL);
	dict = parse_lines(lines);
	free_matrix(lines);
	return (dict);
}
