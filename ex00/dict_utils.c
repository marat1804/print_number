/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:51:32 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 12:51:33 by strisha          ###   ########.fr       */
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
