/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 15:08:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	init_struct(&data);
	if (validate_all_arguments(&data, ac, av) == -1)
		return (-1);
	if (init_semaphores(&data) == -1)
		return (-1);
	philo = init_philosophers(&data);
	if (philo == NULL)
	{
		close_semaphores(&data);
		return (-1);
	}
	execution(&data, philo);
	return (0);
}
