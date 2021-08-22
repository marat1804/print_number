/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_leading_zeros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:28:42 by lcardiga          #+#    #+#             */
/*   Updated: 2021/08/22 16:20:42 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*trim_leading_zeros(char *str, int *did_copy)
{
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == 0)
	{
		*did_copy = 0;
		return (str);
	}
	*did_copy = 1;
	return (ft_strdup(str + i));
}
