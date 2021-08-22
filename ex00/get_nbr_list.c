/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:14:27 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 20:14:28 by strisha          ###   ########.fr       */
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

	i = 1;
	if (nbr[0] == '1')
	{
		while (nbr[i] == '0')
			i++;
		if (i == size)
			return (3);
		return (5);
	}
	else
	{
		return (5);
	}
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
