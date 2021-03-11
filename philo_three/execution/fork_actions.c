/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:11:18 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 14:03:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_message(philo, TAKEN_FORK);
	sem_wait(philo->data->forks);
	print_message(philo, TAKEN_FORK);
	if (philo->data->dead == 1)
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		return ;
	}
	philo->status = EATING;
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->status = SLEEPING;
}
