/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:43:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	*monitor(void *arg)
{
	t_philo			*philo;
	long			difference;

	philo = arg;
	while (philo->data->dead == 0 && philo->times_eaten !=
									philo->data->number_of_times_to_eat)
	{
		pthread_mutex_lock(&philo->data->alive_mutex);
		difference = get_time_in_ms() - philo->time_since_last_meal;
		if (difference > philo->data->time_to_die)
			print_died(philo);
		pthread_mutex_unlock(&philo->data->alive_mutex);
	}
	return (NULL);
}
