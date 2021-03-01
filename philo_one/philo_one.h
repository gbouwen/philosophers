/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/26 14:37:36 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_to_eat;
}				t_data;

// validate_arguments

int		validate_all_arguments(t_data *data, int ac, char **av);
void	incorrect_amount_of_arguments(char *arg);
int		validate_single_argument(t_data *data, char *arg, int index);

// execution

void	execution_loop(t_data *data);

// helper

int		ft_atoi(const char *str);
void	init_struct(t_data *data);

#endif
