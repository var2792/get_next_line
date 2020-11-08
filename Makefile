SRCS		= gnl_main.c get_next_line.c get_next_line_utils.c

OBJ		=	${SRCS:.c=.o}

HEADER		= -I get_next_line.h

CFLAGS		= -Wall -Wextra -Werror

CC			= @gcc

.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM			= @rm -f

NAME		= result

${NAME}:	${OBJ}
			gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h

			gcc -fsanitize=address -fno-omit-frame-pointer -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h
all:		 ${NAME}

			clear && ./a.out

clean:
			${RM} ${OBJ} ${OBNS} *.gch

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re