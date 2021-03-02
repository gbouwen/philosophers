/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:25:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 14:58:56 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	init_struct(t_data *data)
{
	data->number_of_philosophers = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_times_to_eat = 0;
	data->forks = NULL;
	data->dead = 0;
}

int		init_forks(t_data *data)
{
	int	index;

	index = 0;
	data->forks = ft_calloc(data->number_of_philosophers,
													sizeof(pthread_mutex_t));
	if (!data->forks)
		return (0);
	while (index < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[index]), NULL) != 0)
			return (0);
		index++;
	}
	return (1);
}

t_philo		*init_philosophers(t_data *data)
{
	t_philo	*philo;
	t_philo	*begin;
	int		index;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	begin = philo;
	index = 0;
	while (index < data->number_of_philosophers)
	{
		philo->id = index + 1;
		philo->data = data;
		philo->next = malloc(sizeof(t_philo));
		if (!philo->next)
			return (NULL);
		philo = philo->next;
		index++;
	}
	philo->next = NULL;
	return (begin);
}
