all:
	(cd ft_printf && make)
	gcc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server
	gcc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o client
clean:
	(cd ft_printf && make clean && cd .. && rm -f server && rm -f client)
fclean:	clean
	(cd ft_printf && make fclean && cd .. && rm -f server && rm -f client)
re:	fclean	all	
	(cd ft_printf && make re && cd .. && rm -f server && rm -f client)
.PHONY:	all clean fclean re
