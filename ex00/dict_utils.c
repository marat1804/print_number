/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:51:32 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 14:49:17 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dict	*dict_create_elem(char *num, char *word)
{
	t_dict	*tmp;

	tmp = (t_dict *)malloc(sizeof(t_dict));
	tmp->next = NULL;
	tmp->number = num;
	tmp->word = word;
	return (tmp);
}

int		dict_find_elem(t_dict **dict, int pos, char *num)
{
	int		i;
	t_dict	*cur;

	i = 0;
	cur = dict[pos];
	if (dict[pos] == NULL)
		return (-1);
	while (cur != NULL)
	{
		if (ft_strcmp(num, cur->number) == 0)
			return (i);
		cur = cur->next;
		++i;
	}
	return (-1);
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
