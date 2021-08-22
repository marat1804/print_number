/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:22:44 by strisha           #+#    #+#             */
/*   Updated: 2021/08/21 12:22:48 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_argc(int argc, int type)
{
	if (type == 0)
	{
		if (argc == 1)
			ft_putstr("Too few arguments\n");
		else
			ft_putstr("Too many arguments\n");
	}
	else if (type == 1)
		ft_putstr("Error\n");
	else if (type == 2)
		ft_putstr("Dict Error\n");
}

void	print_dict(t_dict **dict)
{
	int		i;
	t_dict	*cur;

	i = 0;
	while (i < 4)
	{
		cur = dict[i];
		while (cur)
		{
			printf("%d - %s - %s\n", i, cur->number, cur->word);
			cur = cur->next;
		}
		i++;
	}
}

void	print_res(t_string	*res)
{
	t_string	*tmp;

	tmp = res;
	while (tmp)
	{
		ft_putstr(tmp->data);
		tmp = tmp->next;
		if (tmp != NULL)
			ft_putstr(" ");
	}
	ft_putstr("\n");
}

int	one_arg_main(char **argv)
{
	t_dict		**dict;
	t_string	*res;
	int			flag;

	if (!ft_valid_number(argv[1]))
		return (-1);
	dict = dict_parse("numbers.dict");
	if (dict == NULL)
		return (-2);	
	print_dict(dict);
	flag = ft_print_nbr(dict, argv[1], &res);
	printf("FLAG - %d\n", flag);
	print_res(res);
	free_dict(dict);
	free_res(res);
	return (0);
}

int	two_arg_main(char **argv)
{
	t_dict		**dict;
	t_string	*res;
	int			flag;

	if (!ft_valid_number(argv[2]))
		return (-1);
	dict = dict_parse(argv[1]);
	if (dict == NULL)
		return (-2);
	//print_dict(dict);
	flag = ft_print_nbr(dict, argv[2], &res);
	printf("FLAG - %d\n", flag);
	print_res(res);
	free_dict(dict);
	free_res(res);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict		**dict;
	t_string	*res;
	int			flag;

	dict = NULL;
	res = NULL;
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			flag = one_arg_main(argv);
		else
			flag = two_arg_main(argv);
		if (flag == -1)
			error_argc(argc, 1);
		else if (flag == -2)
			error_argc(argc, 2);
	}
	else
		error_argc(argc, 0);
	getchar();
	return (0);
}
