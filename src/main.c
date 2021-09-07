/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:42:05 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 09:23:04 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac == 2)
	{
		parse(av[1], &data);
		init_so_long(&data);
		define_hooks(&data);
		exit_so_long(&data, 0);
	}
	else
	{
		exit_so_long(&data, MAIN_ARGS);
	}
	return (0);
}
