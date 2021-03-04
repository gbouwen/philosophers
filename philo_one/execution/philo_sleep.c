/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:09:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 15:41:09 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		philo_sleep(t_philo *philo)
{
	if (check_alive(philo) == 0)
		return ;
	get_total_time_in_ms(philo->data);
	printf("%lu - [philosopher %d] is sleeping\n", philo->data->total_time, philo->id);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}
