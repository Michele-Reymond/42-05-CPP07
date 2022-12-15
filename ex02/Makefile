SRCS	= 	main_intra.cpp #main.cpp

CFLAGS	= -Werror -Wextra -Wall -std=c++98 -pedantic
CC		= g++-12
NAME	= array
OBJS	= ${SRCS:.cpp=.o}
RM		= rm -f

all:	${NAME}

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

run:
	./${NAME}

leaks:
	leaks -atExit -- ./${NAME}

mrun: all run

.PHONY: all clean fclean re run mrun leaks