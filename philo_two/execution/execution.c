/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:36:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 17:29:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

static int	create_threads(pthread_t *threads, int amount, t_philo *philo)
{
	int	index;
	int	ret;

	index = 0;
	ret = 0;
	while (index < amount)
	{
		ret = pthread_create(&threads[index], NULL, philosopher, &philo[index]);
		if (ret != 0)
			return (-1);
		index++;
		usleep(50);
	}
	return (0);
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

void	execution(t_data *data, t_philo *philo)
{
	pthread_t	*threads;

	threads = ft_calloc(data->number_of_philosophers, sizeof(pthread_t));
	if (!threads)
	{
		free(philo);
		return ;
	}
	if (create_threads(threads, data->number_of_philosophers, philo) == 0)
		wait_for_threads(threads, data->number_of_philosophers);
	close_semaphores(data);
	free(threads);
	free(philo);
}
