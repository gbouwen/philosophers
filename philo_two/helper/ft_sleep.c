/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sleep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 10:50:36 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 12:44:53 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

long	get_current_time(void)
{
	struct timeval	time;
	long			now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now * 1000);
}

void	ft_sleep(long time_to_sleep)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < time_to_sleep)
		usleep(100);
}
