/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/03 16:38:55 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		*philosopher(void *arg)
{
	t_philo			*philo;
	int				left;
	int				right;

	philo = arg;
	left = (philo->id + philo->data->number_of_philosophers - 1)
										% philo->data->number_of_philosophers;
	right = (philo->id + 1) % philo->data->number_of_philosophers;
	gettimeofday(&philo->start, NULL);
	while (1)
	{
		if (philo->status == THINKING)
			take_forks(philo, left, right);
		if (philo->status == EATING)
		{
			philo_eat(philo);
			drop_forks(philo, left, right);
		}
		if (philo->status == SLEEPING)
			philo_sleep(philo);
		if (philo->status == THINKING)
			philo_think(philo);
	}
	return (NULL);
}
