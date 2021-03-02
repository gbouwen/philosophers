/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 14:56:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static void	create_threads(pthread_t *threads, int amount, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < amount)
	{
		pthread_create(&threads[index], NULL, philosopher, philo);
		philo = philo->next;
		index++;
	}
}

static void	wait_for_threads(pthread_t *threads, int amount)
{
	int	index;

	index = 0;
	while (index < amount)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
}

int			execution(t_data *data, t_philo *philo)
{
	pthread_t	*threads;

	threads = ft_calloc(sizeof(pthread_t), data->number_of_philosophers);
	if (!threads)
		return (0);
	create_threads(threads, data->number_of_philosophers, philo);
	wait_for_threads(threads, data->number_of_philosophers);
	return (1);
}
