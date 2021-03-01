/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 14:36:32 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (validate_all_arguments(&data, ac, av) == 0)
		return (-1);
	execution_loop(&data);
	return (0);
}
