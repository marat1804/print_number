/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:29:41 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 16:29:42 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_print_nbr(t_dict **dict, char *nbr, t_string **res)
{
	int			i;
	int			len;
	int			s;

	len = ft_strlen(nbr) - 1;
	i = 0;
	while (i <= len)
	{
		if (((len - i) % 3) == 0)
			s = dict_rem_0(dict, nbr[i], res, (len - i));
		else if (((len - i) % 3) == 2)
			s = dict_rem_2(dict, nbr[i], res);
		else
		{
			s = dict_rem_1(dict, nbr[i], nbr[i + 1], res);
			if (nbr[i] == '1')
				nbr[i + 1] = '0';
		}
		if (s == -1)
			return (-1);		//TODO FREE memory
		i++;
	}
	return (0);
}
