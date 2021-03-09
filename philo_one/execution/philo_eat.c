/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:07:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:35:55 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_eat(t_philo *philo)
{
	print_message(philo, EATING);
	ft_sleep(philo->data->time_to_eat * 1000);
	philo->time_since_last_meal = get_time_in_ms();
	philo->times_eaten++;
}
