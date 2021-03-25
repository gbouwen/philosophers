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
	if (validate_all_arguments(&data, ac, av) == -1)
		return (-1);
	if (init_mutexes(&data) == -1)
		return (-1);
	philo = init_philosophers(&data);
	if (philo == NULL)
	{
		free(data.forks);
		return (-1);
	}
	execution(&data, philo);
	return (0);
}
