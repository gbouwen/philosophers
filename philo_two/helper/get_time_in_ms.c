/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time_in_ms.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:19:14 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 17:43:06 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

long long	get_time_in_ms(void)
{
	struct timeval	now;
	long long		time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}
