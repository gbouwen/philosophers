/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:07:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:01:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_eat(t_philo *philo)
{
	print_message(philo->data, EATING, philo->id);
	ft_sleep(philo->data->time_to_eat * 1000);
	philo->times_eaten++;
}
