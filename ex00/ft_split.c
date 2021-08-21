/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:58:45 by strisha           #+#    #+#             */
/*   Updated: 2021/08/15 18:14:27 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	not_separator(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (0);
		sep++;
	}
	return (1);
}

int	skip_(char *str, int i, char *sep, int flag)
{
	if (flag == 0)
	{
		while (*(str + i) != '\0')
		{
			if (!(not_separator(*(str + i), sep)))
				i++;
			else
				return (i);
		}
		return (i);
	}
	else
	{
		while (*(str + i) != '\0')
		{
			if (not_separator(*(str + i), sep))
				i++;
			else
				return (i);
		}
		return (i);
	}
}

char	*split(char *str, int start, int end)
{
	int		i;
	char	*res;

	res = (char *) malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		res[i++] = str[start++];
	}
	res[i] = '\0';
	return (res);
}

int	word_count(char *str, char *charset, int *i)
{
	int	count;
	int	j;
	int	end;

	j = 0;
	count = 0;
	while (*(str + j) != '\0')
	{
		j = skip_(str, j, charset, 0);
		end = skip_(str, j, charset, 1);
		if (j < end)
			count += 1;
		j = end;
	}
	*i = 0;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		end;
	int		i;
	int		count_;
	char	**res;
	int		j;

	count_ = word_count(str, charset, &i);
	res = (char **) malloc (sizeof(char *) * (count_ + 1));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (*(str + i) != '\0')
	{
		i = skip_(str, i, charset, 0);
		end = skip_(str, i, charset, 1);
		if (i < end)
			res[j++] = split(str, i, end);
		i = end;
	}
	res[j] = NULL;
	return (res);
}
