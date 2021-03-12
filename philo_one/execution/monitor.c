/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/12 16:22:16 by gbouwen       ########   odam.nl         */
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
		if (philo[index].status != EATING)
		{
			difference = get_time_in_ms() - philo[index].time_since_last_meal;
			if (difference > philo[index].data->time_to_die)
			{
				philo->data->dead = 1;
				pthread_mutex_lock(&(philo[index].data->print_mutex));
				philo[index].data->total_time = get_time_in_ms() - philo[index].data->start_time;
				printf("%lu philosopher %zu has died\n", philo[index].data->total_time, philo[index].id);
				pthread_mutex_unlock(&(philo[index].data->print_mutex));
				return (NULL);
			}
		}
		index++;
		if (index == number_of_philosophers)
		{
			index = 0;
			usleep(50);
		}
	}
	return (NULL);
}
