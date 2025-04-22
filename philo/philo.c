#include "philo.h"

void	message(void)
{
	printf("ATTENTION YOU SHOULD ENTER THIS PARAMS : < number_of_philosophers time_to_die time_to_eat time_to_sleep[number_of_times_each_philosopher_must_eat] >");
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
		a->time_each_ph_must_eat = 0;
}

int	main(int ac, char **av)
{
	t_params a;
	hp(&a, ac, av);
	printf("SUCCESS :)\n");
	printf("SUCCESS :)\n");
	printf("num of philosophers = %ld\n", a.num_philo);
	printf("time to die = %ld\n", a.time_to_die);
	printf("time to eat = %ld\n", a.time_to_eat);
	printf("time to sleep = %ld\n", a.time_to_sleep);
	if (ac == 6)
		printf("times each philosopher must eat = %ld\n",
			a.time_each_ph_must_eat);

	if (a.num_philo < 0 || a.time_to_die < 0 || a.time_to_eat < 0
		|| a.time_to_sleep < 0 || (a.time_each_ph_must_eat < 0 && ac == 6))
	{
		printf("\nDO NOT TRY TO OVERFLOW THE PROCESS HONEY!");
		exit(1);
	}
}