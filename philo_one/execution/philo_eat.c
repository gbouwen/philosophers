/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:07:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 10:54:48 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void			philo_eat(t_philo *philo)
{
	get_time_in_ms(philo);
	printf("%lu - [philosopher %d] is eating\n", philo->time, philo->id);
	//usleep(philo->data->time_to_eat * 1000);
	ft_sleep(philo->data->time_to_eat * 1000);
}
