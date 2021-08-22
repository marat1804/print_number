/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlurleen <zlurleen@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:14:27 by strisha           #+#    #+#             */
/*   Updated: 2021/08/22 15:40:48 by zlurleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	validate_big_number(char *nbr, int size)
{
	int	i;

	i = 0;
	if (nbr[0] != '1')
		return (5);
	while (nbr[i + 1] == '0')
		i++;
	if (i + 1 != size)
		return (5);
	if (i == 0 || (i != 2 && i % 3))
		return (5);
	return (3);
}

int	get_nbr_list(char *nbr)
{
	int	size;

	size = ft_strlen(nbr);
	if (size == 1 && is_number(nbr[0]))
		return (0);
	if (size == 2 && is_number(nbr[0]) && is_number(nbr[1]))
	{
		if (nbr[0] == '1')
			return (1);
		else if (nbr[1] == '0')
			return (2);
		return (5);
	}
	return (validate_big_number(nbr, size));
}
