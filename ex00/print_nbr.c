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
#include <stdio.h>
int	ft_print_nbr(t_dict **dict, char *nbr, t_string **res)
{
	int			i;
	int			len;
	int			rem;
	int			s;

	i = ft_strlen(nbr);
	len = --i;
	while (i >= 0)
	{
		rem = (len - i) % 3;
		if (rem == 0)
			s = dict_rem_0(dict, nbr[len - i], res, i);
		else if (rem == 2)
			s = dict_rem_2(dict, nbr[len - i], res);
		else
			s = dict_rem_1(dict, nbr[len - i], nbr[len - i + 1], res);
		if (s == -1)
			return (-1);		//TODO FREE memory
		i--;
	}
	return (0);
}
