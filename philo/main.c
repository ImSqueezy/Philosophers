#include "philo.h"

int	parser(t_info *info, int ac, char **argv)
{
	int	i;
	int	data;

	if (ac != 5 && ac != 6)
		return (printf("%s", USAGE_ERROR), 0);
	(*info).meals = 0;
	i = 0;
	while (++i < ac)
	{
		data = arg_checker(argv[i], i);
		if (data == -1)
			return (printf("%s", ARGS_ERROR), 0);
		else
			fill(i, data, info);
	}
	if ((*info).philos == INT_MIN)
		return (printf("%s", RANGE_ERROR), 0);
	return (1);
}

void	initializer(t_info *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->meal, NULL))
		printf("Mutex initialization failed\n");
	if (pthread_mutex_init(&data->print, NULL))
		printf("Mutex initialization failed\n");
	while (i < data->philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			printf("Mutex initialization failed\n");
		i++;
	}

}

void	create_philo(t_info *info)
{
	int		i;

	i = 0;
	while (i < (*info).philos)
	{
		(*info).philo[i].id = i;
		(*info).philo[i].right = i;
		(*info).philo[i].left = (i + 1) & (*info).philos;
		(*info).
		i++;
	}
}

int main(int argc, char **argv)
{
	t_info	info;

	if (parser(&info, argc, argv))
	{
		initializer(&info);
	}
	return (0);
}
