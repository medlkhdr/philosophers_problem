#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#define EAT "is eating"
#define DONE "is done eating"
#define THINK "is thinking"
#define FORK "has taken a fork"
#define SLEEP "is sleeping"
#define DEAD "died :("
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
	pthread_t threadt;
	bool dead;
	pthread_mutex_t *meal_mutex ;
	unsigned long last_meal; 
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
} t_philo;

unsigned long filter(char *string);

#endif