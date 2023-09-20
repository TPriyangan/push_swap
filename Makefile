NAME	= push_swap

SRCS	= push_swap.c push_methods.c
OBJS	= ${SRCS:.c=.o}

HEADER	= push_swap.h

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

all: 		${NAME}

${NAME}:	${OBJS}
	@make re -C ./pushswap
	@$(CC) ${OBJS} -Lpushswap -lft -o ${NAME}

clean:
	@make clean -C ./pushswap
	@rm -f ${OBJS}

fclean: 	clean
	@make fclean -C ./pushswap
	@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re 
