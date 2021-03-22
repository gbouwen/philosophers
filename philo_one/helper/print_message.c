/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:07:59 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	print_message(t_philo *philo, int message_id)
{
	pthread_mutex_lock(&(philo->data->print_mutex));
	if (philo->data->dead == 1 || philo->times_eaten == philo->data->number_of_times_to_eat)
	{
		pthread_mutex_unlock(&(philo->data->print_mutex));
		return ;
	}
	philo->total_time = get_time_in_ms() - philo->start_time;
	if (message_id == TAKEN_FORK)
		printf("%lu philosopher %zu has taken a fork\n", philo->total_time, philo->id);
	else if (message_id == EATING)
		printf("%lu philosopher %zu is eating\n", philo->total_time, philo->id);
	else if (message_id == SLEEPING)
		printf("%lu philosopher %zu is sleeping\n", philo->total_time, philo->id);
	else if (message_id == THINKING)
		printf("%lu philosopher %zu is thinking\n", philo->total_time, philo->id);
	pthread_mutex_unlock(&(philo->data->print_mutex));
}

void	print_died(t_philo *philo)
{
	philo->data->dead = 1;
	pthread_mutex_lock(&philo->data->print_mutex);
	philo->total_time = get_time_in_ms() - philo->start_time;
	printf("%lu philosopher %zu has died\n", philo->total_time, philo->id);
	pthread_mutex_unlock(&(philo->data->print_mutex));
}
