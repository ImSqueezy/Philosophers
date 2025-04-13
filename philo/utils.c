#include "philo.h"

long	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		right_most;

	while (*str && (*str == 32 || *str == '\t'))
		str++;
	sign = 1;
	res = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		right_most = (*str - '0') * sign;
		if (res > (INT_MAX / 10) || (res == (INT_MAX / 10) && right_most > 7))
			return (2147483648);
		if (res < (INT_MIN / 10) || (res == (INT_MIN / 10) && right_most < -8))
			return (2147483648);
		res = res * 10 + right_most;
		str++;
	}
	return (res);
}

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

int	arg_checker(char *arg)
{
	int	data;
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	data = ft_atoi(arg);
	if (data < 0)
		return (-1);
	return (data);
}
