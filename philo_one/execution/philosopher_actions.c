/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher_actions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:23:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 14:53:10 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void		*philosopher(void *arg)
{
	t_philo	*philo;
	int		left;
	int		right;

	philo = arg;
	left = (philo->id + 5 - 1) % 5;
	right = (philo->id + 1) % 5;
	while (1)
	{
		printf("this is philosopher %d speaking\n", philo->id);
		printf("taking this fork %d\n", left);
		printf("taking this fork %d\n", right);
		usleep(100000);
   /*     take_forks(data, left, right);*/
		/*if (data->state[data->index] == EATING)*/
			/*philo_eat(data);*/
		/*put_forks(data, left, right);*/
		/*philo_sleep(data);*/
	}
	return (NULL);
}
