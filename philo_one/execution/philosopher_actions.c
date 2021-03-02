/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher_actions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 16:38:34 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		philo_sleep(t_philo *philo, int times)
{
	printf("%d [philosopher %d] is sleeping\n", times, philo->id);
	usleep(philo->data->time_to_sleep);
	philo->status = THINKING;
}

void		put_forks(t_philo *philo, int left, int right)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	philo->status = SLEEPING;
}

void		philo_eat(t_philo *philo, int times)
{
	printf("%d [philosopher %d] is eating\n", times, philo->id);
	usleep(philo->data->time_to_eat);
}

void		take_forks(t_philo *philo, int left, int right, int times)
{
	pthread_mutex_lock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->forks[left]);
	printf("%d [philosopher %d] has taken left fork\n", times, philo->id);
	pthread_mutex_lock(&philo->data->forks[right]);
	pthread_mutex_unlock(&philo->data->mutex);
	printf("%d [philosopher %d] has taken right fork\n", times, philo->id);
	philo->status = EATING;
}

void		*philosopher(void *arg)
{
	t_philo	*philo;
	int		left;
	int		right;
	int		times;

	philo = arg;
	left = (philo->id + philo->data->number_of_philosophers - 1)
										% philo->data->number_of_philosophers;
	right = (philo->id + 1) % philo->data->number_of_philosophers;
	times = 0;
	while (1)
	{
		take_forks(philo, left, right, times);
		if (philo->status == EATING)
			philo_eat(philo, times);
		put_forks(philo, left, right);
		if (philo->status == SLEEPING)
			philo_sleep(philo, times);
		if (philo->status == THINKING)
			printf("%d [philosopher %d] is thinking\n", times, philo->id);
		times++;
	}
	return (NULL);
}
