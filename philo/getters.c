#include "philo.h"
#include <limits.h>

ssize_t	filter(char *string)
{
	int		i;
	ssize_t	res;

	res = 0;
	i = 0;
	if (string[i] == '-')
	{
		printf("NO NEGATIVE NUMBERS PLEASE!\n");
		printf("THE NUMBER YOU ENTERED IS INVALID IN MY PROJECT : %s", string);
		exit(1);
	}
	if (string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		if (res > 4294967295)
		{
			printf("overflow !!! \n");
			exit(1);
		}
		res = res * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] != '\0')
	{
		printf("INVALID PARAM: %s\n", string);
		exit(1);
	}
	return (res);
}
