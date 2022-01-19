/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:37:38 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/19 18:47:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdlib.h>
# include "color.h"

# define LIFE 0
# define DEATH 1
# define SUCCESS 0
# define ERROR 1

/* Error message list */
# define ARG_ERROR				"The format of the argument is incorrect"
# define MALLOC_ERROR			"Failed to allocate memory"
# define THREAD_CREATE_ERROR	"Failed to create thread"

/* Log message list */
# define TAKEAFORK_M	"has taken a fork"
# define EATING_M		"is eating"
# define SLEEPING_M		"is sleeping"
# define THINKING_M		"is thinking"
# define DIED_M			"died"

typedef enum e_log_num
{
	TAKEAFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_log_num;

typedef struct s_options
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}	t_options;

typedef struct s_log_message
{
	char	*color;
	char	*message;
}	t_log_message;

typedef struct s_philo_data
{
	int				philo_id;
	struct timeval	time;
	long long		time_ate;
	bool			is_death;
}	t_philo_data;

typedef struct s_thread_data
{
	pthread_t	*philo_treads;
	pthread_t	*monitor_treads;
	pthread_t	main_monitor_tread;
}	t_thread_data;

typedef struct s_mutex_data
{
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	put_log_mutex;
	pthread_mutex_t	death_info_mutex;
}	t_mutex_data;

typedef struct s_philos_data
{
	int	philo_id;
	int	death_flag;
	int	death_time;
	int	*eat_cnt;
}	t_philos_data;

typedef struct s_management_data
{
	t_options		opts;
	t_thread_data	thread;
	t_mutex_data	mutex;
	t_philos_data	philos;
	t_log_message	log_message[5];
	bool			is_error;
}	t_management_data;

typedef struct s_action_data
{
	t_philo_data	philo;
	t_options		*opts;
	t_thread_data	*thread;
	t_mutex_data	*mutex;
	t_philos_data	*philos;
	t_log_message	*log_message;
	bool			*is_error;
}	t_action_data;

/*  Function prototype */

int			check_arg(int ac, char **av);
bool		check_int(const char *str);
long		ft_long_atoi(const char *str);
int			set_management_data(int ac, char **av, t_management_data *md);
int			ft_atoi(const char *str);
void		set_log_message(t_management_data *md);
int			run_simulation(t_management_data *md);
void		*main_monitor(void *arg);
void		*philo_action(void *arg);
void		*death_monitor(void *arg);
void		put_log(t_action_data *ad, int log_num);
long long	get_ms(struct timeval *time);
int			finish_error(char *error_message);
void		free_management_data(t_management_data *md);
void		free_action_data(t_action_data *ad);
int			ft_isspace(char a);

#endif
