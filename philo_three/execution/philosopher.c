/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 17:50:02 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	*philosopher(void *arg)
{
	t_philo		*philo;
	pthread_t	monitor_thread;

	philo = arg;
	if (pthread_create(&monitor_thread, NULL, monitor, philo) != 0)
		return (NULL);
	philo->start_time = get_time_in_ms();
	philo->time_since_last_meal = philo->start_time;
	while (philo->data->dead == 0 && philo->times_eaten
		!= philo->data->number_of_times_to_eat)
	{
		if (philo->status == THINKING && philo->data->dead == 0)
			take_forks(philo);
		if (philo->status == EATING && philo->data->dead == 0)
			philo_eat(philo);
		if (philo->status == SLEEPING && philo->data->dead == 0)
			philo_sleep(philo);
		if (philo->status == THINKING && philo->data->dead == 0)
			philo_think(philo);
	}
	pthread_join(monitor_thread, NULL);
	return (NULL);
}
