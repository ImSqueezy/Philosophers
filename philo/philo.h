#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	int	number_of_meals;
	int	right;
	int	left;
	int	meal_count;
	int	philo_order;
	t_info	*info;
} t_philo;

typedef struct info
{
	int	forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meats;
	int	status; // time of death
	int	index; // index of the philo
	t_philo	philo[200];
} t_info;

# define ARGS_ERROR "Invalid arg!\n"
# define USAGE_ERROR "Usage: ./philo number_of_philos time_to_die time_to_eat \
time_to_sleep [number_of_meats]\n"
# define RANGE_ERROR "The philosophers must range between 1 and 200.\n"


void	fill(int flag, int num, t_info *info);
int		arg_checker(char *arg);
long	ft_atoi(char *str);

#endif