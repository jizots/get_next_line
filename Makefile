#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hotph <hotph@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 11:27:21 by hotph             #+#    #+#              #
#    Updated: 2024/09/12 12:13:05 by hotph            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = a.out

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = ../main.c get_next_line.c get_next_line_utils.c

BSRCS = ../main.c get_next_line_bonus.c get_next_line_utils_bonus.c

SRCS_DIR = srcs
OBJS_DIR = objs

ifdef WITH_EXE_BONUS
	SRCS = $(BSRCS)
	CFLAGS += -D EXE_BONUS
endif

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(OBJS_DIR) $(NAME)

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

exe_bonus: 
	$(MAKE) WITH_EXE_BONUS=1 all

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
