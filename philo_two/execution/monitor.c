/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:44:37 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	*monitor(void *arg)
{
	t_philo			*philo;
	unsigned int	index;
	unsigned int	number_of_philosophers;
	long			now;
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
			now = get_time_in_ms();
			difference = now - philo[index].time_since_last_meal;
			if (difference > philo[index].data->time_to_die)
			{
				philo->data->dead = 1;
				//semaphore shit
				get_total_time_in_ms(philo[index].data);
				printf("%lu philosopher %d has died\n", philo[index].data->total_time, philo[index].id);
				//semaphore shit
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
