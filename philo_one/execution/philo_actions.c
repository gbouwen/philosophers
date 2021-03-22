/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 10:59:20 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:16:05 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	take_forks(t_philo *philo, size_t left, size_t right)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		print_message(philo, TAKEN_FORK);
		pthread_mutex_lock(&philo->data->forks[left]);
		print_message(philo, TAKEN_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		print_message(philo, TAKEN_FORK);
		pthread_mutex_lock(&philo->data->forks[right]);
		print_message(philo, TAKEN_FORK);
	}
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
		return ;
	}
	philo->status = EATING;
}

static void	drop_forks(t_philo *philo, size_t left, size_t right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}

void	philo_eat(t_philo *philo, size_t left, size_t right)
{
	pthread_mutex_lock(&philo->data->alive_mutex);
	philo->time_since_last_meal = get_time_in_ms();
	print_message(philo, EATING);
	pthread_mutex_unlock(&philo->data->alive_mutex);
	ft_sleep(philo->data->time_to_eat * 1000);
	philo->times_eaten++;
	drop_forks(philo, left, right);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	philo_think(t_philo *philo)
{
	print_message(philo, THINKING);
}
