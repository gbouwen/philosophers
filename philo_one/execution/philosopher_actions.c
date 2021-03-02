/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher_actions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 15:45:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		philo_sleep(t_philo *philo)
{
	printf("philosopher %d is sleeping\n", philo->id);
	usleep(philo->data->time_to_sleep);
	philo->status = THINKING;
}

void		put_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}

void		philo_eat(t_philo *philo)
{
	printf("philosopher %d is eating\n", philo->id);
	usleep(philo->data->time_to_eat);
}

void		take_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->forks[left]);
	printf("philosopher %d has taken left fork\n", philo->id);
	pthread_mutex_lock(&philo->data->forks[right]);
	pthread_mutex_unlock(&philo->data->mutex);
	printf("philosopher %d has taken right fork\n", philo->id);
	philo->status = EATING;
}

void		*philosopher(void *arg)
{
	t_philo	*philo;
	int		left;
	int		right;

	philo = arg;
	left = (philo->id + 5 - 1) % 5;
	right = (philo->id + 1) % 5;
	while (1)
	{
		take_forks(philo, left, right);
		if (philo->status == EATING)
			philo_eat(philo);
		put_forks(philo, left, right);
		if (philo->status == SLEEPING)
			philo_sleep(philo);
		if (philo->status == THINKING)
			printf("philosopher %d is thinking\n", philo->id);
	}
	return (NULL);
}
