/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:09:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 10:57:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		philo_sleep(t_philo *philo)
{
	get_time_in_ms(philo);
	printf("%lu - [philosopher %d] is sleeping\n", philo->time, philo->id);
	//usleep(philo->data->time_to_sleep * 1000);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}
