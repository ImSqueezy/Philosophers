#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				number_of_meals;
	int				right;
	int				left;
	pthread_t		thread;
	struct s_info	*data;
} t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				philos;
	int				start;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
}	t_info;

# define ARGS_ERROR "Invalid arg!\n"
# define USAGE_ERROR "Usage: ./philo number_of_philos time_to_die time_to_eat \
time_to_sleep [number_of_meats]\n"
# define RANGE_ERROR "The philosophers must range between 1 and 200.\n"


void	fill(int flag, int num, t_info *info);
int		arg_checker(char *arg, int flag);

#endif