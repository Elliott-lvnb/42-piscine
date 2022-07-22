SRCS	= ft_display_file.c ft_putstr_file_desc.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $^ -o ${NAME}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}\

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
