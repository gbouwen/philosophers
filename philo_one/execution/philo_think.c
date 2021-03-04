/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:08:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 17:28:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_think(t_philo *philo)
{
	if (check_alive(philo) == 0)
		return ;
	get_total_time_in_ms(philo->data);
	printf("%lu - [philosopher %d] is thinking\n", philo->data->total_time, philo->id);
}
