/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:50:46 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 10:50:48 by strisha          ###   ########.fr       */
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
	if (tmp[i] == '\0' && i != 0)
		*num = tmp;
	free(words);
	if (i == 0)
		return (0);
	tmp[i] = '\0';
	*num = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	parse_word(char *str, char **word)
{
	char	**words;

	words = ft_split(str, " ");
	if (word_count_in_matrix(words) == 0)
		return (0);
	*word = ft_strjoin(word_count_in_matrix(words), words, " ");
	free_matrix(words);
	return (1);
}

int	parse_one_line(t_dict **dict, char *str)
{
	int		flag;
	char	**lines;
	char	*num;
	char	*word;

	if (!replace_first_colon(str))
		return (0);
	lines = ft_split(str, "\n");
	if (!parse_num(lines[0], &num))
		return (0);
	if (!parse_word(lines[1], &word))
		return (0);
	flag = get_nbr_list(num);
	if (flag < 5)
	{
		dict_push_elem(dict, flag, num, word);
	}
	return (1);
}

t_dict	**parse_lines(char **lines)
{
	t_dict	**dict;

	dict = dict_init();
	while (*lines != NULL)
	{
		if (!parse_one_line(dict, *lines))
			break ; // TODO CLEAN MEMORY
		lines++;
	}
	return (dict);
}

t_dict	**dict_parse(char *filename, int *error)
{
	t_dict	**dict;
	char	**lines;

	lines = get_lines(filename, error);
	if (*error)
		return (NULL);
	dict = parse_lines(lines);
	return (dict);
}