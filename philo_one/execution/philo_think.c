/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:08:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/03 16:23:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		philo_think(t_philo *philo)
{
	get_time_in_ms(philo);
	printf("%lu - [philosopher %d] is thinking\n", philo->time, philo->id);
}
