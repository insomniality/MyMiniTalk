#!/bin/bash
gcc -Wall -Wextra server.c ft_printf/libftprintf.a -o server
gcc -Wall -Wextra  client.c ft_printf/libftprintf.a -o client
