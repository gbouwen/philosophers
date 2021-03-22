/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/22 14:32:18 by gbouwen       ########   odam.nl         */
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

typedef struct s_data
{
	size_t			number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_times_to_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
	int				dead;
}	t_data;

typedef struct s_philo
{
	size_t			id;
	t_data			*data;
	long long		start_time;
	long long		total_time;
	size_t			left;
	size_t			right;
	int				times_eaten;
	int				status;
	long long		time_since_last_meal;
}	t_philo;

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3
# define TAKEN_FORK 4

// validate_arguments

int				validate_all_arguments(t_data *data, int ac, char **av);
void			incorrect_amount_of_arguments(char *arg);
int				validate_single_argument(t_data *data, char *arg, int index);

// execution

int				execution(t_data *data, t_philo *philo);
void			*philosopher(void *data);
void			*monitor(void *philo);
void			take_forks(t_philo *philo, size_t left, size_t right);
void			philo_eat(t_philo *philo, size_t left, size_t right);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

// helper

int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			init_struct(t_data *data);
int				init_mutexes(t_data *data);
t_philo			*init_philosophers(t_data *data);
void			ft_sleep(long time);
long			get_time_in_ms(void);
int				check_alive(t_philo *philo);
void			destroy_mutexes(t_data *data);
void			print_message(t_philo *philo, int message_id);
void			print_died(t_philo *philo);

#endif
