# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 09:52:18 by vlaroque          #+#    #+#              #
#    Updated: 2019/04/19 01:48:15 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES
SRC_FILES := fdf.c ft_image.c ft_parsing.c ft_readfile.c ft_segment.c ft_printgrid.c

# HEADERS NAME
INCLUDES_NAME := fdf.h ft_image.h ft_parsing.h ft_readfile.h ft_segment.h

# PATH
SRC_PATH := ./src/
OBJ_PATH := ./obj/
INCLUDES_PATH := ./inc/

# ASSIGNATION SOURCES
SRC := $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ := $(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

# ASSIGNATION INCLUDES
HEADER := $(addprefix $(INCLUDES_PATH),$(INCLUDES_NAME))

# COMPILATION
NAME := Fdf
CC := clang
CFLAGS := -Wall -Wextra #-Weverything #-Wno-padded# -Werror
FLAGS := -lmlx -framework OpenGL -framework AppKit

# RULES
all: $(NAME) 

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@ $(FLAGS)
	@echo "\033[32m$(NAME) generated with succes !\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES_PATH) $(FLAGS)
	@echo "\033[32mObject's updateded : $@ !\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mObject's removed with succes !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mLibrary removed with succes !\033[0m"

re: fclean all

.PHONY: all clean fclean re