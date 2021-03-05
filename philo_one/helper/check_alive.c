/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_alive.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 15:24:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/05 12:41:34 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int	check_alive(t_philo *philo)
{
	unsigned long	now;
	unsigned long	difference;

	now = get_time_in_ms();
	difference = now - philo->time;
	if (difference >= philo->data->time_to_die)
	{
		philo->status = DEAD;
		philo->data->dead++;
		return (0);
	}
	return (1);
}
