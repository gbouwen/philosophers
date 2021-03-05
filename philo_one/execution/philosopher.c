/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/05 12:49:53 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	*philosopher(void *arg)
{
	t_philo			*philo;
	unsigned int	left;
	unsigned int	right;

	philo = arg;
	left = philo->id - 1;
	if (philo->id < philo->data->number_of_philosophers)
		right = philo->id;
	else
		right = 0;
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
		if (philo->times_eaten == philo->data->number_of_times_to_eat)
			break ;
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
