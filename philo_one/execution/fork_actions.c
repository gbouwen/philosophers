/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/03 16:38:22 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		take_forks(t_philo *philo, int left, int right)
{
	get_time_in_ms(philo);
	pthread_mutex_lock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->forks[left]);
	printf("%lu - [philosopher %d] has taken a fork\n", philo->time, philo->id);
	pthread_mutex_lock(&philo->data->forks[right]);
	printf("%lu - [philosopher %d] has taken a fork\n", philo->time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex);
	philo->status = EATING;
}

void		drop_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}
