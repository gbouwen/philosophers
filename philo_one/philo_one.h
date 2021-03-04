/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 11:25:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/03/04 16:18:44 by gbouwen       ########   odam.nl         */
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
	unsigned int	number_of_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned int	number_of_times_to_eat;
	struct timeval	start;
	unsigned long	total_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	int				dead;
}				t_data;

typedef struct			s_philo
{
	int					id;
	t_data				*data;
	int					status;
	unsigned long		time;
}						t_philo;

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3

// validate_arguments

int		validate_all_arguments(t_data *data, int ac, char **av);
void	incorrect_amount_of_arguments(char *arg);
int		validate_single_argument(t_data *data, char *arg, int index);

// execution

int		execution(t_data *data, t_philo *philo);
void	*philosopher(void *data);
void	take_forks(t_philo *philo, int left, int right);
void	drop_forks(t_philo *philo, int left, int right);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// helper

int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			init_struct(t_data *data);
int				init_forks(t_data *data);
t_philo			*init_philosophers(t_data *data);
void			ft_sleep(unsigned long time);
void			get_total_time_in_ms(t_data *data);
unsigned long	get_time_in_ms(void);
int				check_alive(t_philo *philo);
void			destroy_mutexes(t_data *data);

#endif
