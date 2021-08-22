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
	char		*num;

	if (!ft_valid_number(argv[1]))
		return (-1);
	num = trim_leading_zeros(argv[1], 0);
	dict = dict_parse("numbers.dict");
	if (dict == NULL)
		return (-2);
	flag = ft_print_nbr(dict, num, &res);
	if (flag == -1)
		error_argc(1, 2);
	else
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
	char		*num;

	if (!ft_valid_number(argv[2]))
		return (-1);
	num = trim_leading_zeros(argv[2], 0);
	dict = dict_parse(argv[1]);
	if (dict == NULL)
		return (-2);
	flag = ft_print_nbr(dict, num, &res);
	if (flag == -1)
		error_argc(1, 2);
	else
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
	return (0);
}
