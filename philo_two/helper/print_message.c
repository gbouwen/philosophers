/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 15:50:30 by gbouwen       ########   odam.nl         */
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
	get_total_time_in_ms(philo->data);
	if (message_id == TAKEN_FORK)
		printf("%lu philosopher %d has taken a fork\n", philo->data->total_time, philo->id);
	else if (message_id == EATING)
		printf("%lu philosopher %d is eating\n", philo->data->total_time, philo->id);
	else if (message_id == SLEEPING)
		printf("%lu philosopher %d is sleeping\n", philo->data->total_time, philo->id);
	else if (message_id == THINKING)
		printf("%lu philososopher %d is thinking\n", philo->data->total_time, philo->id);
	sem_post(philo->data->print_semaphore);
}
