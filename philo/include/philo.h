/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:37:38 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/16 15:15:00 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libphilo/libphilo.h"
# include "color.h"

# define LIFE 0
# define DEATH 1
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

typedef struct s_tread_data
{
	pthread_t	*philo_treads;
	pthread_t	*monitor_treads;
	pthread_t	main_monitor_tread;
}	t_tread_data;

typedef struct s_mutex_data
{
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	put_log_mutex;
	pthread_mutex_t	death_info_mutex;
}	t_mutex_data;

typedef struct s_philos_data
{
	int				philo_id;
	int				death_flag;
	int				death_time;
	int				*eat_cnt;
}	t_philos_data;

typedef struct	s_management_data
{
	t_options		opts;
	t_mutex_data	mutex;
	t_philo_data	*philo;
	t_philos_data	philos;
	t_tread_data	tread;
	t_log_message	t_log_message[5];
}	t_management_data;

/* Global variables */

// t_philos_data	g_philos_data;
// t_mutex_data	g_mutex_data;
// t_tread_data	g_tread_data;
// t_options		g_opts;
// t_log_message	g_log_message[5];

/*  Function prototype */

void		check_arg(int ac, char **av);
void		set_global_data(int ac, char **av);
void		set_log_message(void);
void		run_simulation(void);
void		*main_monitor(void *arg);
void		*philo_action(void *arg);
void		*death_monitor(void *arg);
void		put_log(t_philo_data *philo, int log_num);
long long	get_ms(struct timeval *time);
void		finish_error(char *error_message);
void		free_all(void);

#endif