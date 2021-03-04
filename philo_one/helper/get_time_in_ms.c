/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time_in_ms.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:19:14 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 13:52:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	get_total_time_in_ms(t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	philo->time = ((philo->now.tv_sec - philo->start.tv_sec) * 1000) +
						((philo->now.tv_usec - philo->start.tv_usec) / 1000);
}
