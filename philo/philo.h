#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

struct					s_params
{
	ssize_t				num_philo;
	ssize_t				time_to_die;
	ssize_t				time_to_eat;
	ssize_t				time_to_sleep;
	ssize_t				time_each_ph_must_eat;
};
typedef struct s_params	t_params;

ssize_t					filter(char *string);
#endif