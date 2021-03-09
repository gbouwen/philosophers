/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:31:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:05:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	print_message(t_data *data, int message_id, unsigned int philo_id)
{
	pthread_mutex_lock(&(data->print_mutex));
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&(data->print_mutex));
		return ;
	}
	get_total_time_in_ms(data);
	if (message_id == TAKEN_FORK)
		printf("%lu philosopher %d has taken a fork\n", data->total_time, philo_id);
	else if (message_id == EATING)
		printf("%lu philosopher %d is eating\n", data->total_time, philo_id);
	else if (message_id == SLEEPING)
		printf("%lu philosopher %d is sleeping\n", data->total_time, philo_id);
	else if (message_id == THINKING)
		printf("%lu philososopher %d is thinking\n", data->total_time, philo_id);
	pthread_mutex_unlock(&(data->print_mutex));
}
