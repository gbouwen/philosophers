/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:25:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:33:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	init_struct(t_data *data)
{
	data->number_of_philosophers = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_times_to_eat = -1;
	data->forks = NULL;
	data->dead = 0;
}

int	init_mutexes(t_data *data)
{
	size_t	index;

	index = 0;
	data->forks = ft_calloc(data->number_of_philosophers,
			sizeof(pthread_mutex_t));
	if (!data->forks)
		return (-1);
	while (index < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[index], NULL) != 0)
		{
			free(data->forks);
			return (-1);
		}
		index++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->alive_mutex, NULL) != 0)
	{
		free(data->forks);
		return (-1);
	}
	return (0);
}

static size_t	get_right_fork_index(size_t id, size_t number_of_philosophers)
{
	if (id < number_of_philosophers)
		return (id);
	return (0);
}

t_philo	*init_philosophers(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	if (!philo)
	{
		free(data->forks);
		return (NULL);
	}
	index = 0;
	while (index < data->number_of_philosophers)
	{
		philo[index].id = index + 1;
		philo[index].data = data;
		philo[index].start_time = 0;
		philo[index].total_time = 0;
		philo[index].left = philo[index].id - 1;
		philo[index].right = get_right_fork_index(philo[index].id,
				data->number_of_philosophers);
		philo[index].times_eaten = 0;
		philo[index].status = THINKING;
		philo[index].time_since_last_meal = 0;
		index++;
	}
	return (philo);
}
