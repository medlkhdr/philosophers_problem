/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:47:12 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/04/22 21:48:22 by mlakhdar         ###   ########.fr       */
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
void *handlep(void *arg)
{
	t_philo *p;
	p = arg;
	printf("Philosopher ID: %lu, Index: %d\n", p->threadt, p->index);
	printf("Hello! I am philosopher %d, and I am starting my routine.\n", p->index);
	printf("I have completed my task and will now terminate. Goodbye from thread %lu.\n", p->threadt);
	return NULL;
}
void init_solution( t_params a )
{
	unsigned long i =0;
	t_philo p[200] ; 
	while(i < a.num_philo)
	{
		p[i].arg = a;
		p[i].index = i;
		pthread_mutex_init(&p[i].f , NULL);
		pthread_create(&p[i].threadt , NULL , &handlep , (void *)&p[i]);
		i++;
	}
	i = 0;
	while (i < a.num_philo)
	{
		pthread_join(p[i].threadt, NULL);
		pthread_mutex_destory(&p[i].f);
		i++;
	}
}
int	main(int ac, char **av)
{

	t_params a;
	hp(&a, ac, av);
	init_solution( a );
}
