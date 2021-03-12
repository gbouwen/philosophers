/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/12 16:26:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	long	now;
	long	difference;

	philo = arg;
	usleep(philo->data->time_to_die * 10);
	while (1)
	{
		if (philo->times_eaten == philo->data->number_of_times_to_eat)
			return (NULL);
		if (philo->status != EATING)
		{
			now = get_time_in_ms();
			difference = now - philo->time_since_last_meal;
			if (difference > philo->data->time_to_die)
			{
				philo->data->dead = 1;
				sem_wait(philo->data->print_semaphore);
				philo->data->total_time = get_time_in_ms() - philo->data->start_time;
				printf("%lu philosopher %zu has died\n", philo->data->total_time, philo->id);
				sem_post(philo->data->dead_semaphore);
				return (NULL);
			}
		}
		usleep(50);
	}
	return (NULL);
}
