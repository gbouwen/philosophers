/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:09:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/09 16:02:00 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_sleep(t_philo *philo)
{
	print_message(philo->data, SLEEPING, philo->id);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}
