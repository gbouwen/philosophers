/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 16:33:07 by gbouwen       ########   odam.nl         */
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
	gettimeofday(&philo->data->start, NULL);
	while (1)
	{
		philo->time = get_time_in_ms();
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
		if (philo->status == DEAD && philo->data->dead == 1)
		{
			get_total_time_in_ms(philo->data);
			printf("%lu - [philosopher %d] died\n", philo->data->total_time, philo->id);
			break ;
		}
		if (philo->data->dead > 0)
			break ;
	}
	return (NULL);
}
