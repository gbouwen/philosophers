/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 14:26:05 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (validate_all_arguments(&data, ac, av) == 0)
		return (-1);
	printf("number of philosophers: %d\n", data.number_of_philosophers);
	printf("time to die: %d\n", data.time_to_die);
	printf("time to eat: %d\n", data.time_to_eat);
	printf("time to sleep: %d\n", data.time_to_sleep);
	printf("number of times to eat: %d\n", data.number_of_times_to_eat);
	return (0);
}
