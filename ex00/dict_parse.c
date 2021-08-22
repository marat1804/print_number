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

int	get_filelen(char *filename)
{
	int		fd;
	int		len;
	int		r;
	char	c[4096];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = 0;
	while (1)
	{
		r = read(fd, c, 4096);
		len += r;
		if (r < 4096)
			break ;
	}
	close(fd);
	return (len);
}

char	**get_lines(char *filename, int *error)
{
	int		fd;
	int		len;
	char	*buf;
	char	**lines;

	len = get_filelen(filename);
	if (len == -1)
	{
		*error = -1;
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	buf = (char *) malloc(sizeof(char) * (len + 1));
	read(fd, buf, len);
	buf[len] = '\0';
	close(fd);
	lines = ft_split(buf, "\n");
	free(buf);
	return (lines);
}

int	replace_first_colon(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ':')
		{
			str[i] = '\n';
			return (1);
		}
		i++;
	}
	return (0);
}

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
	while (tmp[i] >='0' && tmp[i] <= '9')
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

t_dict	*dict_create_elem(char *num, char *word)
{
	t_dict	*tmp;

	tmp = (t_dict *)malloc(sizeof(t_dict));
	tmp->next = NULL;
	tmp->number = num;
	tmp->word = word;
	return (tmp);
}

void	dict_push_elem(t_dict **dict, int pos, char *num, char *word)
{
	t_dict	*tmp;

	if (dict[pos] == NULL)
		dict[pos] = dict_create_elem(num, word);
	else
	{
		tmp = dict_create_elem(num, word);
		tmp->next = dict[pos];
		dict[pos] = tmp;
	}
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
		/*entry = (t_dict *) malloc(sizeof(t_dict));
		entry->next = NULL;
		printf("%s\n", *lines);
		i = 0;
		len = 0;
		while ('0' <= *lines[len] && *lines[len] <= '9')
			++len;
		entry->number = (char *) malloc(sizeof(char) * len);
		while ('0' <= *lines[i] && *lines[i] <= '9')
		{
			entry->number[i] = *lines[i];
			++i;
		}
		entry->number[i] = '\0';
		while (*lines[i] != ':')
			++i;
		++i;
		while (*lines[i] == ' ')
			++i;
		len = 0;
		while (*lines[len] != '\0')
			++len;
		entry->word = (char *) malloc(sizeof(char) * len);
		len = 0;
		while (*lines[i + len] != '\0')
		{
			entry->word[len] = *lines[i + len];
			++len;
		}
		entry->word[len] = '\0';
		i = get_nbr_list(entry->number);
		if (i < 5)
		{
			if (dict[i] != NULL)
				dict[i]->next = entry;
			dict[i] = entry;
		}
		++lines;*/
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
