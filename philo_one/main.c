/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:51:55 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	init_struct(&data);
	if (validate_all_arguments(&data, ac, av) == 0)
		return (-1);
	if (init_mutexes(&data) == 0)
		return (-1);
	philo = init_philosophers(&data);
	if (philo == NULL)
		return (-1);
	if (execution(&data, philo) == 0)
		return (-1);
	return (0);
}
