/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:42:30 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 19:27:39 by zlurleen         ###   ########.fr       */
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
	dict = (t_dict **) malloc(sizeof(t_dict *) * 4);	 //without custom
	len = 0;
	r = read(fd, &c, 1);
	while (r)
	{
		r = read(fd, &c, 1);
		++len;
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	buf = (char *) malloc(sizeof(char) * len);
	r = read(fd, buf, len);
	return ft_split(buf, "\n");
}

t_dict	**parse_lines(char **lines, int *error)
{
	int		len;

	while (*lines != NULL)
	{
		printf("%s\n", *lines);
		len = 0;
		while ('0' <= *lines[len] && *lines[len] <= '9')
			++len;
		i = 0;
		++lines;
	}
}

t_dict	**dict_parse(char *filename, int *error)
{
	t_dict	**dict;
	int		i;
	int		len;
	char	**lines;
	
	lines = get_lines(filename, error);
	if (*error)
		return (NULL);
	dict = parse_lines(lines, error);
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