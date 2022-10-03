#!/bin/bash
gcc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server
gcc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o client
