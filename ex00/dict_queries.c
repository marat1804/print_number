/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_queries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:57:25 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 16:57:27 by strisha          ###   ########.fr       */
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
		elem = find_string(dict[0], str); //TODO	единицы
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
	}
	if (i == 0)
		return (0);
	free(str);
	str = ft_num_to_str('1', i);
	elem = find_string(dict[3], str);		//TODO		10^х
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	free(str);
	return (0);
}

int	dict_rem_2(t_dict **dict, char c, t_string **res)
{
	char	*elem;
	char	*str;

	if (c == '0')
		return (0);
	str = ft_num_to_str(c, 0);
	elem = find_string(dict[0], str); //TODO	единицы	
	free(str);
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	str = ft_num_to_str('1', 2);
	elem = find_string(dict[3], str);		//TODO		10^х
	free(str);
	if (elem == NULL)
		return (-1);
	ft_list_push_back(res, elem);
	return (0);
}

int	dict_rem_1(t_dict **dict, char c, char d, t_string **res)
{
	char	*elem;
	char	*str;

	if (c == '1')
	{
		str = (char *)malloc(sizeof(char) * 3);
		str[0] = c;
		str[1] = d;
		str[2] = '\0';
		elem = find_string(dict[1], str); //TODO	10-19		
		free(str);
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
	}
	else
	{
		str = ft_num_to_str(c, 1);
		elem = find_string(dict[2], str); //TODO	20-90		
		free(str);
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
	}
	return (0);
}