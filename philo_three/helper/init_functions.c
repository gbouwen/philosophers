/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 14:25:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 18:03:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	init_struct(t_data *data)
{
	data->number_of_philosophers = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_times_to_eat = -1;
	data->forks = NULL;
	data->print_semaphore = NULL;
	data->alive_semaphore = NULL;
	data->dead_semaphore = NULL;
	data->process_id = NULL;
	data->dead = 0;
}

int	init_semaphores(t_data *data)
{
	data->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR,
			data->number_of_philosophers);
	if (data->forks == SEM_FAILED)
		return (-1);
	sem_unlink("/forks");
	data->print_semaphore = sem_open("/print", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->print_semaphore == SEM_FAILED)
		return (-1);
	sem_unlink("/print");
	data->alive_semaphore = sem_open("/alive", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->alive_semaphore == SEM_FAILED)
		return (-1);
	sem_unlink("/alive");
	data->dead_semaphore = sem_open("/dead", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->dead_semaphore == SEM_FAILED)
		return (-1);
	sem_unlink("/dead");
	sem_wait(data->dead_semaphore);
	return (0);
}

t_philo	*init_philosophers(t_data *data)
{
	t_philo			*philo;
	unsigned int	index;

	philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	if (!philo)
		return (NULL);
	data->process_id = ft_calloc(data->number_of_philosophers, sizeof(int));
	if (!data->process_id)
	{
		free(philo);
		return (NULL);
	}
	index = 0;
	while (index < data->number_of_philosophers)
	{
		philo[index].id = index + 1;
		philo[index].data = data;
		philo[index].start_time = 0;
		philo[index].total_time = 0;
		philo[index].times_eaten = 0;
		philo[index].status = THINKING;
		philo[index].time_since_last_meal = 0;
		index++;
	}
	return (philo);
}
