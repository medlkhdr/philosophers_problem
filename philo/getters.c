/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:47:16 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/04/22 21:47:32 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define LIMIT 4294967295
unsigned long	filter(char *string)
{
	int		i;
	unsigned long	res;

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
		if (res > LIMIT)
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
