/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/12 11:09:20 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

static void	create_threads(pthread_t *threads, int amount, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < amount)
	{
		pthread_create(&threads[index], NULL, philosopher, &philo[index]);
		index++;
		usleep(50);
	}
	pthread_create(&threads[index], NULL, monitor, philo);
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

int	execution(t_data *data, t_philo *philo)
{
	pthread_t	*threads;

	threads = ft_calloc(data->number_of_philosophers + 1, sizeof(pthread_t));
	if (!threads)
	{
		free(philo);
		return (0);
	}
	create_threads(threads, data->number_of_philosophers, philo);
	wait_for_threads(threads, data->number_of_philosophers + 1);
	close_semaphores(data);
	free(threads);
	free(philo);
	return (1);
}
