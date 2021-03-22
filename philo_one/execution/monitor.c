/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:14:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	*monitor(void *arg)
{
	t_philo			*philo;
	size_t			index;
	size_t			number_of_philosophers;
	long			difference;

	philo = arg;
	index = 0;
	number_of_philosophers = philo[index].data->number_of_philosophers;
	while (1)
	{
		if (philo[index].times_eaten == philo[index].data->number_of_times_to_eat)
			return (NULL);
		pthread_mutex_lock(&philo->data->alive_mutex);
		difference = get_time_in_ms() - philo[index].time_since_last_meal;
		if (difference > philo[index].data->time_to_die)
		{
			print_died(&philo[index]);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->alive_mutex);
		index++;
		if (index == number_of_philosophers)
			index = 0;
	}
	return (NULL);
}
