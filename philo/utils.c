#include "philo.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

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
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	arg_checker(char *arg)
{
	int	data;
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '-' && arg[i] != '+')
			return (printf("returned"), 0);
		i++;
	}
	data = ft_atoi(arg);
	if (data < 0)
		return (0);
	return (data);
}