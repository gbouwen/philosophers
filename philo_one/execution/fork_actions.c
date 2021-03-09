/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:00:56 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	take_forks(t_philo *philo, unsigned int left, unsigned int right)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		print_message(philo->data, TAKEN_FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[left]);
		print_message(philo->data, TAKEN_FORK, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		print_message(philo->data, TAKEN_FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[right]);
		print_message(philo->data, TAKEN_FORK, philo->id);
	}
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
		return ;
	}
	philo->status = EATING;
}

void	drop_forks(t_philo *philo, unsigned int left, unsigned int right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}
