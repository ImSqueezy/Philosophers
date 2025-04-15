NAME = philo

OBJS = main.o utils.o

COMPILE = cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

.o: %.c philo.h
	$(COMPILE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: clean