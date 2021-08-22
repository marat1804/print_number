/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:24:44 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 17:24:45 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_list_push_back(t_string **begin_list, char *data)
{
	t_string	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_string *)malloc(sizeof(t_string));
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->data = data;
	}
	else
	{
		tmp = (t_string *)malloc(sizeof(t_string));
		tmp->next = NULL;
		tmp->data = data;
		*begin_list = tmp;
	}
}	

char	*ft_num_to_str(char c, int i)
{
	char	*s;
	int		j;

	s = (char *)malloc(sizeof(char) * (i + 2));
	j = 0;
	s[j++] = c;
	while (j <= i)
		s[j++] = '0';
	s[j] = '\0';
	return (s);
}
