/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:42:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 17:45:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	*monitor(void *arg)
{
	t_philo			*philo;
	long long		difference;

	philo = arg;
	while (1)
	{
		usleep(500);
		sem_wait(philo->data->alive_semaphore);
		difference = get_time_in_ms() - philo->time_since_last_meal;
		if (difference > philo->data->time_to_die)
		{
			print_died(philo);
			return (NULL);
		}
		sem_post(philo->data->alive_semaphore);
	}
	return (NULL);
}
