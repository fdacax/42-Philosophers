MAKEFLAGS += -s
NAME= philo
CC= cc -g -Wall -Wextra -Werror -pthread -fsanitize=thread
SRCS= $(wildcard *.c)
OBJS= $(SRCS:.c=.o)
RM= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "The philosophers are ready!"

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "Objects were removed!"

fclean: clean
	$(RM) $(NAME)
	@echo "All philosophers die! :("

re: fclean all
