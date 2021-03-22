/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 18:04:30 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	print_message(t_philo *philo, int message_id)
{
	sem_wait(philo->data->print_semaphore);
	if (philo->data->dead == 1 || philo->times_eaten == philo->data->number_of_times_to_eat)
	{
		sem_post(philo->data->print_semaphore);
		return ;
	}
	philo->total_time = get_time_in_ms() - philo->start_time;
	if (message_id == TAKEN_FORK)
		printf("%llu philosopher %zu has taken a fork\n", philo->total_time, philo->id);
	else if (message_id == EATING)
		printf("%llu philosopher %zu is eating\n", philo->total_time, philo->id);
	else if (message_id == SLEEPING)
		printf("%llu philosopher %zu is sleeping\n", philo->total_time, philo->id);
	else if (message_id == THINKING)
		printf("%llu philosopher %zu is thinking\n", philo->total_time, philo->id);
	sem_post(philo->data->print_semaphore);
}

void	print_died(t_philo *philo)
{
	if (philo->data->dead == 1)
		return ;
	philo->data->dead = 1;
	sem_wait(philo->data->print_semaphore);
	philo->total_time = get_time_in_ms() - philo->start_time;
	printf("%llu philosopher %zu has died\n", philo->total_time, philo->id);
	sem_post(philo->data->print_semaphore);
	sem_post(philo->data->dead_semaphore);
}
