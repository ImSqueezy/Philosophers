#include "philo.h"

int	parser(t_info *info, int ac, char **argv)
{
	int	i;
	int	data;

	if (ac != 5 && ac != 6)
		return (printf("%s", USAGE_ERROR), 0);
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
	if (i < 6)
		(*info).meals = -1;
	return (1);
}

// void	initializer()
// {

// }

int main(int argc, char **argv)
{
	t_info	info;

	if (parser(&info, argc, argv))
	{
		// will initialize with that the mutexes, data and create and join threads
		// initializer();
		printf("success");
	}
	return (0);
}
