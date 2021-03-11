/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_single_argument.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 12:16:44 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/11 13:58:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

static void	add_to_struct(t_data *data, int value, int index)
{
	if (index == 1)
		data->number_of_philosophers = value;
	else if (index == 2)
		data->time_to_die = value;
	else if (index == 3)
		data->time_to_eat = value;
	else if (index == 4)
		data->time_to_sleep = value;
	else if (index == 5)
		data->number_of_times_to_eat = value;
}

static void	correct_error_message(int index)
{
	if (index == 1)
		printf("[number_of_philosophers] ");
	else if (index == 2)
		printf("[time_to_die] ");
	else if (index == 3)
		printf("[time_to_eat] ");
	else if (index == 4)
		printf("[time_to_sleep] ");
	else if (index == 5)
		printf("[number_of_times_each_philosopher_must_eat] ");
	printf("cannot be zero/less than zero OR is not a numeric value\n");
}

int	validate_single_argument(t_data *data, char *arg, int index)
{
	int	value;

	value = ft_atoi(arg);
	if (value <= 0)
	{
		correct_error_message(index);
		return (0);
	}
	else
		add_to_struct(data, value, index);
	return (1);
}
