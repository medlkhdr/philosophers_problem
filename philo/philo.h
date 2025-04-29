#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_params
{
	unsigned long num_philo;
	unsigned long time_to_die;
	unsigned long time_to_eat;
	unsigned long time_to_sleep;
	unsigned long time_each_ph_must_eat;
} t_params;


typedef struct s_philo
{
	t_params arg;
	int index;
	pthread_t threadt ;
	pthread_mutex_t mutext ;
}t_philo;

unsigned long filter(char *string);

#endif