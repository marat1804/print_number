/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:42:30 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 13:42:32 by strisha          ###   ########.fr       */
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

char	*copy_str(char *s, int start, int end)
{

}

t_dict	**dict_parse(char *filename, int *error)
{
	t_dict	**dict;
	int		fd;
	int		r;
	char	buf;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		*error = 1;
		return (NULL);
	}
	dict = (t_dict **)malloc(sizeof(t_dict *) * 4);	 //without custom
	r = 1;
	while (r)
	{
		//r = read(fd, buf, BUF_SIZE);
	}
}