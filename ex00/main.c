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
	{
		ft_putstr("Error\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_valid_number(argv[1]))
			error_argc(argc, 1);
			
		// загрузка словаря базового
		// вывод числа
	}
	else if (argc == 3)
	{
		if (!ft_valid_number(argv[2]))
			error_argc(argc, 1);
		// загрузка кастомного словаря
		// вывод числа
	}
	else
	{
		error_argc(argc, 0);
	}
}
