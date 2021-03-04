/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 17:28:53 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	take_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (check_alive(philo) == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		return ;
	}
	pthread_mutex_lock(&philo->data->forks[left]);
	if (check_alive(philo) == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_unlock(&philo->data->forks[left]);
		return ;
	}
	get_total_time_in_ms(philo->data);
	printf("%lu - [philosopher %d] has taken a fork\n", philo->data->total_time, philo->id);
	pthread_mutex_lock(&philo->data->forks[right]);
	if (check_alive(philo) == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
		return ;
	}
	get_total_time_in_ms(philo->data);
	printf("%lu - [philosopher %d] has taken a fork\n", philo->data->total_time, philo->id);
	pthread_mutex_unlock(&philo->data->mutex);
	philo->status = EATING;
}

void	drop_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}
