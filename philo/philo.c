/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedback <feedback@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:47:12 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/04/30 23:30:37 by feedback         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(void)
{
	printf("ERROR: Invalid arguments.\n");
	printf("Usage: ./philo <number_of_philosophers> ");
	printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	exit(1);
}

void	hp(t_params *a, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		message();
	a->num_philo = filter(av[1]);
	a->time_to_die = filter(av[2]);
	a->time_to_eat = filter(av[3]);
	a->time_to_sleep = filter(av[4]);
	if (ac == 6)
		a->time_each_ph_must_eat = filter(av[5]);
	else
		a->time_each_ph_must_eat = -1;
}


void philo_eat(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
	printf("philo %d is eating ...\n",p->index + 1 );
	usleep(p->arg.time_to_eat * 1000);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}
void philo_think()
{
	printf("thinking...\n");
}
void philo_sleep(t_philo *p)
{
	printf("sleeping...\n");
	usleep(p->arg.time_to_sleep * 1000);
}


void *handlep(void *arg)
{
	t_philo *p = arg;
	unsigned long counted = 0;

	while (p->arg.time_each_ph_must_eat == -1 || counted < p->arg.time_each_ph_must_eat)
	{
		philo_eat(p);
		philo_sleep(p);
		philo_think();
		counted++;
	}
	printf("philo %d is done eating.\n", p->index + 1);
	return NULL;
}
void init_solution(t_params a)
{
	t_philo p[200];
	pthread_mutex_t forks[200];
	unsigned long i = 0;

	while (i < a.num_philo)
		pthread_mutex_init(&forks[i++], NULL);

	i = 0;
	while (i < a.num_philo)
	{
		p[i].arg = a;
		p[i].index = i;
		p[i].left_fork = &forks[i];
		p[i].right_fork = &forks[(i + 1) % a.num_philo];
		pthread_create(&p[i].threadt, NULL, &handlep, (void *)&p[i]);
		i++;
	}

	i = 0;
	while (i < a.num_philo)
	{
		pthread_join(p[i].threadt, NULL);
		i++;
	}

	i = 0;
	while (i < a.num_philo)
		pthread_mutex_destroy(&forks[i++]);
}

int	main(int ac, char **av)
{

	t_params a;
	hp(&a, ac, av);
	init_solution( a );
}
