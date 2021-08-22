/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:57:35 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 12:57:37 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_matrix(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
		free(words[i++]);
	free(words);
}

void	free_dict(t_dict **dict)
{
	int		i;
	t_dict	*tmp;
	t_dict	*cur;

	i = 0;
	while (i < 4)
	{
		tmp = dict[i];
		while (tmp)
		{
			cur = tmp->next;
			free(tmp->number);
			free(tmp->word);
			free(tmp);
			tmp = cur;
		}
		i++;
	}
	free(dict);
}

void	free_res(t_string *str)
{
	t_string	*cur;

	while (str)
	{
		cur = str->next;
		free(str->data);
		free(str);
		str = cur;
	}
}
