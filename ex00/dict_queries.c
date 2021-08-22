/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_queries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:57:25 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 16:41:14 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*find_string(t_dict *dict, char *c)
{
	t_dict	*res;

	res = dict;
	while (res)
	{
		if (ft_strcmp(c, res->number) == 0)
			return (ft_strdup(res->word));
		res = res->next;
	}
	return (NULL);
}

int	dict_rem_0(t_dict **dict, char c, t_string **res, int i)
{
	char	*elem;
	char	*str;

	if (c != '0')
	{
		str = ft_num_to_str(c, 0);
		elem = find_string(dict[0], str);
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
		free(str);
	}
	if (i == 0)
		return (0);
	str = ft_num_to_str('1', i);
	elem = find_string(dict[3], str);
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	free(str);
	return (0);
}

int	dict_rem_2(t_dict **dict, char *nbr, t_string **res, int i)
{
	char	*elem;
	char	*str;

	if (nbr[i] == '0')
		return (0);
	str = ft_num_to_str(nbr[i], 0);
	elem = find_string(dict[0], str);
	free(str);
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	str = ft_num_to_str('1', 2);
	elem = find_string(dict[3], str);
	free(str);
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	return (0);
}

int	dict_rem_1(t_dict **dict, char *nbr, int i, t_string **res)
{
	char	*elem;
	char	*str;

	if (nbr[i] == '1')
	{
		str = init_str(nbr, i);
		elem = find_string(dict[1], str);
		free(str);
		nbr[i + 1] = '0';
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
	}
	else if (nbr[i] != '0')
	{
		str = ft_num_to_str(nbr[i], 1);
		elem = find_string(dict[2], str);
		free(str);
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
	}
	return (0);
}

t_dict	**dict_init(void)
{
	t_dict	**dict;
	int		i;

	dict = (t_dict **) malloc(sizeof(t_dict *) * DICT_SIZE);
	i = 0;
	while (i < DICT_SIZE)
	{
		dict[i] = NULL;
		++i;
	}
	return (dict);
}
