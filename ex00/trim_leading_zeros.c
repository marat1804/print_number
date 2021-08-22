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

int	is_skip(char c)
{
	if (c == '0' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*trim_leading_zeros(char *str, int do_copy)
{
	int		i;
	char	*res;

	i = 0;
	while (is_skip(str[i]))
		i++;
	if (str[i] == '\0')
	{
		if (do_copy)
		{
			free(str);
			return (ft_strdup("0"));
		}
		return ("0");
	}
	if (i != 0)
	{
		if (do_copy)
		{
			res = ft_strdup(str + i);
			free(str);
			return (res);
		}
	}
	return (str + i);
}

char	*validate_plus(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] == '\t')
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	if (i != 0)
	{
		res = ft_strdup(str + i);
		free(str);
		return (res);
	}
	return (str);
}
