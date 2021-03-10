/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time_in_ms.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:19:14 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:43:59 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	get_total_time_in_ms(t_data *data)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	data->total_time = ((now.tv_sec - data->start.tv_sec) * 1000) + ((now.tv_usec - data->start.tv_usec) / 1000);
}

unsigned long	get_time_in_ms(void)
{
	struct timeval	now;
	unsigned long	time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}
