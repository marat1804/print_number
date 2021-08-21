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

void	error_argc(int argc)
{
	if (argc == 1)
		ft_putstr("Too few arguments\n");
	else 
		ft_putstr("Too many arguments\n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = NULL;
		// чтение числа
		// загрузка словаря базового
		// вывод числа
	}
	else if (argc == 3)
	{
		// чтение числа
		// загрузка кастомного словаря
		// вывод числа
	}
	else
	{
		error_argc(argc);
	}
}