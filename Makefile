# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:05:57 by uxmancis          #+#    #+#              #
#    Updated: 2023/12/27 17:15:41 by uxmancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Source files and object files
SRC1 = server.c utils1.c utils2.c
OBJ1 = $(SRC1:.c=.o)
# OBJ1 = server.o utils1.o utils2.o

# Executable names
NAME1 = server
NAME2 = client

# Source files and object files
SRC2 = client.c utils1.c utils2.c
OBJ2 = $(SRC2:.c=.o)

# Make all rule
all: $(NAME1) $(NAME2)

# Build the executable: server
$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

# Build the executable: client
$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

# Clean everything, including the executable
fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re