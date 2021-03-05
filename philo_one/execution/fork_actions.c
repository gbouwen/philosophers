/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/05 12:48:36 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	take_forks(t_philo *philo, unsigned int left, unsigned int right)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		get_total_time_in_ms(philo->data);
		printf("%lu - [philosopher %d] has taken a [RIGHT] fork\n", philo->data->total_time, philo->id);
		pthread_mutex_lock(&philo->data->forks[left]);
		get_total_time_in_ms(philo->data);
		printf("%lu - [philosopher %d] has taken a [LEFT] fork\n", philo->data->total_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		get_total_time_in_ms(philo->data);
		printf("%lu - [philosopher %d] has taken a [LEFT] fork\n", philo->data->total_time, philo->id);
		pthread_mutex_lock(&philo->data->forks[right]);
		get_total_time_in_ms(philo->data);
		printf("%lu - [philosopher %d] has taken a [RIGHT] fork\n", philo->data->total_time, philo->id);
	}
	if (check_alive(philo) == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
		return ;
	}
	philo->status = EATING;
}

void	drop_forks(t_philo *philo, unsigned int left, unsigned int right)
{
	philo->time = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}
