SRCS =	push_swap.c parse_input.c sort.c ft_atoi.c operations.c sort_utils.c linked_list.c utils.c process.c process2.c process_move_to_a.c

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)

NAME = 	push_swap

CC = 	gcc

CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

$(OBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY : 		all clean fclean re bonus