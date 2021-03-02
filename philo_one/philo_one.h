/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/02 15:00:07 by gbouwen       ########   odam.nl         */
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
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	pthread_mutex_t	*forks;
	int				dead;
}				t_data;

typedef struct	s_philo
{
	int				id;
	t_data			*data;
	struct s_philo	*next;
}				t_philo;

# define THINKING 0
# define EATING 1
# define SLEEPING 2

// validate_arguments

int		validate_all_arguments(t_data *data, int ac, char **av);
void	incorrect_amount_of_arguments(char *arg);
int		validate_single_argument(t_data *data, char *arg, int index);

// execution

int		execution(t_data *data, t_philo *philo);
void	*philosopher(void *data);

// helper

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	init_struct(t_data *data);
int		init_forks(t_data *data);
t_philo	*init_philosophers(t_data *data);

#endif
