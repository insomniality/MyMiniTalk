SRCS	=	$(shell find . -name "*.c")

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a
	
all: $(NAME)

$(NAME): ${OBJS}
	cc -Wall -Wextra -Werror -c $(SRCS)
	ar csr libftprintf.a ${OBJS}
clean:
	rm -f ${OBJS} 
fclean:	clean
	rm -f $(NAME)
re:	fclean	all		

.PHONY:	all clean fclean re
