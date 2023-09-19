NAME	= push_swap

SRCS	= push_swap.c push_methods.c
OBJS	= ${SRCS:.c=.o}

MAIN	= push_swap.c

HEADER	= push_swap.h

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g

.c.o:	%.o : %.c
	@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
	@make re -C ./libft
	@$(CC) ${OBJS} -Llibft -lft -o ${NAME}

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: 	clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re 
