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
		if (r == -1)
			return (-1);
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

int	all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' \
		|| str[i] == '\r')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
