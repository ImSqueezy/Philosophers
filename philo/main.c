#include "philo.h"

// parser will take the argmunets
// store the data on smth, and checks for errors
//		- number of philos & forks
//		- time to die
//		- time to eat
//		- time to sleep
//		- number of meats

typedef struct info
{
	int	forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meats;
} t_info;

void	fill(int flag, int num, t_info *info)
{
	if (flag == 1)
		(*info).forks = num;
	else if (flag == 2)
		(*info).time_to_die = num;
	else if (flag == 3)
		(*info).time_to_eat = num;
	else if (flag == 4)
		(*info).time_to_sleep = num;
	else if (flag == 5)
		(*info).number_of_meats = num;
}

int main(int argc, char **argv)
{
	t_info	info;
	int		i;
	int		data;

	if (argc != 5 && argc != 6)
		return (printf("Error: Invalid number of args!"), 1);
	i = 0;
	while (++i < argc)
	{
		data = arg_checker(argv[i]);
		if (!data)
			return (printf("Error: Invalid args!"), 0);
		else
			fill(i, data, &info);
	}
	printf("forks %d time_to_die %d time_to_eat %d time_to_sleep %d number_of_meats %d\n", info.forks, info.time_to_die ,info.time_to_eat, info.time_to_sleep, info.number_of_meats);
	return (0);
}
