/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   incorrect_amount_of_arguments.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:54:14 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 11:54:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	incorrect_amount_of_arguments(char *arg)
{
	printf("Incorrect amount of arguments. Give arguments like this:\n");
	printf("%s [number_of_philosophers] [time_to_die] [time_to_eat] ", arg);
	printf("[time_to_sleep] [number_of_times_each_philosopher_must_eat ");
	printf("(optional)]\n");
}

