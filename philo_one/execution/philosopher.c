/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 15:50:03 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

size_t	get_right_fork(size_t philo_id, size_t number_of_philosophers)
{
	if (philo_id < numer_of_philosophers)
		return (philo_id);
	return (0);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	size_t	left;
	size_t	right;

	philo = arg;
	left = philo->id - 1;
	right = get_right_fork(philo->id, philo->data->number_of_philosophers);
	philo->time_since_last_meal = get_time_in_ms();
	while (1)
	{
		if (philo->status == THINKING && philo->data->dead == 0)
			take_forks(philo, left, right);
		if (philo->status == EATING && philo->data->dead == 0)
		{
			philo_eat(philo);
			drop_forks(philo, left, right);
		}
		if (philo->status == SLEEPING && philo->data->dead == 0)
			philo_sleep(philo);
		if (philo->status == THINKING && philo->data->dead == 0)
			philo_think(philo);
		if (philo->data->dead == 1)
			break ;
		if (philo->times_eaten == philo->data->number_of_times_to_eat)
			break ;
	}
	return (NULL);
}
