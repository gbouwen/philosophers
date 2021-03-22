/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 17:32:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 17:45:33 by gbouwen       ########   odam.nl         */
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

static void	drop_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->status = SLEEPING;
}

void	philo_eat(t_philo *philo)
{
	print_message(philo, EATING);
	philo->time_since_last_meal = get_time_in_ms();
	ft_sleep(philo->data->time_to_eat * 1000);
	philo->times_eaten++;
	drop_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, SLEEPING);
	ft_sleep(philo->data->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	philo_think(t_philo *philo)
{
	print_message(philo, THINKING);
}
