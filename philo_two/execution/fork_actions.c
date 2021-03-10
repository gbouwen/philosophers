/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/10 14:44:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	take_forks(t_philo *philo)
{
	//semaphore shit
	philo->status = EATING;
}

void	drop_forks(t_philo *philo)
{
	//semaphore shit
	philo->status = SLEEPING;
}
