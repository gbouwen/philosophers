/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:09:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:44:48 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	philo_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}
