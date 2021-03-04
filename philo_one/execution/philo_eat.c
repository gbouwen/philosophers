/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:07:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 17:28:55 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_eat(t_philo *philo)
{
	if (check_alive(philo) == 0)
		return ;
	get_total_time_in_ms(philo->data);
	printf("%lu - [philosopher %d] is eating\n", philo->data->total_time, philo->id);
	ft_sleep(philo->data->time_to_eat * 1000);
}
