/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 13:06:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	print_message(t_philo *philo, int message_id)
{
	sem_wait(philo->data->print_semaphore);
	if (philo->data->dead == 1 || philo->times_eaten == philo->data->number_of_times_to_eat)
	{
		sem_post(philo->data->print_semaphore);
		return ;
	}
	philo->data->total_time = get_time_in_ms() - philo->data->start_time;
	if (message_id == TAKEN_FORK)
		printf("%lu philosopher %zu has taken a fork\n", philo->data->total_time, philo->id);
	else if (message_id == EATING)
		printf("%lu philosopher %zu is eating\n", philo->data->total_time, philo->id);
	else if (message_id == SLEEPING)
		printf("%lu philosopher %zu is sleeping\n", philo->data->total_time, philo->id);
	else if (message_id == THINKING)
		printf("%lu philosopher %zu is thinking\n", philo->data->total_time, philo->id);
	sem_post(philo->data->print_semaphore);
}
