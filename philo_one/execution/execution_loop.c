/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution_loop.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 15:22:15 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

// lock the forks, unlock them when done eating

void	philosopher(void *id)
{
	while (1)
	{
		take_forks(); // lock forks
		eat();
		put_forks(); // unlock forks
		sleep();
		think();
	}
}

void	execution_loop(t_data *data)
{
	int	amount;

	amount = 0;
	while (philosopers < data->number_of_philosophers)
	{
		pthread_create(, , philosopher, &amount);
		philosophers++;
	}
}
