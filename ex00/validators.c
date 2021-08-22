/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:42:30 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 20:56:40 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	ft_valid_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
char	*copy_str(char *s, int start, int end)
{

}
*/

char	**get_lines(char *filename, int *error)
{
	int		fd;
	int		len;
	int		r;
	char	c;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		*error = 1;
		return (NULL);
	}
	len = 0;
	r = read(fd, &c, 1);
	while (r)
	{
<<<<<<< HEAD
		r = read(fd, buf, BUF_SIZE);
=======
		r = read(fd, &c, 1);
		++len;
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	buf = (char *) malloc(sizeof(char) * len);
	r = read(fd, buf, len);
	return ft_split(buf, "\n");
}

t_dict	**parse_lines(char **lines)
{
	t_dict	**dict;
	t_dict	*entry;
	int		len;
	int		i;

	dict = (t_dict **) malloc(sizeof(t_dict *) * 5);
	i = 0;
	while (i < 5)
	{
		dict[i] = NULL;
		++i;
	}
	while (*lines != NULL)
	{
		entry = (t_dict *) malloc(sizeof(t_dict));
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
		++lines;
>>>>>>> 130aa0041ba2ffe1848d16093ad3c6be34a44060
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

// /*
int	main(int argc, char **argv)
{
	int	error;

	if (argc != 2)
	{
		write(2, "Bruh.\n", 6);
		return (1);
	}
	error = 0;
	dict_parse(argv[1], &error);
	return (0);
}
// */