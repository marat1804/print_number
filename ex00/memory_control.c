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
	int		flag;

	i = 0;
	flag = 0;
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

int	free_word_num(char *word, char *num, int flag_num, int flag_word)
{
	if (flag_num == 0 && flag_word == 1)
		free(word);
	else if (flag_num == 1 & flag_word == 1)
	{
		free(word);
		free(num);
	}
	else if (flag_num == 1 && flag_word == 0)
		free(num);
	return (0);
}
