/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:36:26 by gbouwen       ########   odam.nl         */
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
	get_total_time_in_ms(philo->data);
	if (message_id == TAKEN_FORK)
		printf("%lu philosopher %d has taken a fork\n", philo->data->total_time, philo->id);
	else if (message_id == EATING)
		printf("%lu philosopher %d is eating\n", philo->data->total_time, philo->id);
	else if (message_id == SLEEPING)
		printf("%lu philosopher %d is sleeping\n", philo->data->total_time, philo->id);
	else if (message_id == THINKING)
		printf("%lu philososopher %d is thinking\n", philo->data->total_time, philo->id);
	pthread_mutex_unlock(&(philo->data->print_mutex));
}
