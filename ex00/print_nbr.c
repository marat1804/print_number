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

int	check_zero(t_dict **dict, char *nbr, t_string **res)
{
	char	*elem;
	char	*str;

	if (ft_strlen(nbr) == 1 && nbr[0] == '0')
	{
		str = ft_num_to_str('0', 0);
		elem = find_string(dict[0], str);
		if (elem == NULL)
			return (-1);
		ft_list_push_back(res, elem);
		free(str);
		return (1);
	}
	return (0);
}

int	check_next_three(int len, int i, char *nbr)
{
	if ((len - i) % 3 == 2)
	{
		if (nbr[i] == '0' && nbr[i + 1] == '0' && nbr[i + 2] == '0')
			return (1);
	}
	return (0);
}

int	ft_print_nbr(t_dict **dict, char *nbr, t_string **res)
{
	int			i;
	int			len;
	int			s;

	len = ft_strlen(nbr) - 1;
	i = 0;
	if (check_zero(dict, nbr, res))
		return (0);
	while (i <= len)
	{
		if (check_next_three(len, i, nbr))
		{
			i += 3;
			continue;
		}
		if (((len - i) % 3) == 0)
			s = dict_rem_0(dict, nbr[i], res, (len - i));
		else if (((len - i) % 3) == 2)
			s = dict_rem_2(dict, nbr, res, i);
		else
		{
			s = dict_rem_1(dict, nbr[i], nbr[i + 1], res);
			if (nbr[i] == '1')
				nbr[i + 1] = '0';
		}
		if (s == -1)
			return (-1);
		i++;
	}
	return (0);
}
