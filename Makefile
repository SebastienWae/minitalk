# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:33:22 by swaegene          #+#    #+#              #
#    Updated: 2022/03/22 14:07:00 by swaegene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

FT_PRINTF = libftprintf.a

MKDIR = mkdir
RM = rm -f
AR = ar rsu
CP = cp
MV = mv

SRC_DIR = ./src/
INC_DIR = ./include/
FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF_INC_DIR = $(FT_PRINTF_DIR)/include/

ifdef MAKE_DEBUG
OUT_DIR = ./debug/
NAME := $(OUT_DIR)$(NAME)
SERVER := $(OUT_DIR)$(SERVER)
CLIENT := $(OUT_DIR)$(CLIENT)
DIRS += $(OUT_DIR)
CFLAGS = -g3 -fsanitize=address
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Werror -Wextra -MD
CPPFLAGS += -I$(INC_DIR) -I$(FT_PRINTF_INC_DIR)

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_OBJS = $(addprefix $(OUT_DIR),$(CLIENT_SRCS:%.c=%.o))
SERVER_OBJS = $(addprefix $(OUT_DIR),$(SERVER_SRCS:%.c=%.o))

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(DIRS) $(CLIENT_OBJS) $(FT_PRINTF_DIR)$(FT_PRINTF)

$(SERVER): $(DIRS) $(SERVER_OBJS) $(FT_PRINTF_DIR)$(FT_PRINTF)

all: $(NAME)

bonus: $(NAME)

$(FT_PRINTF_DIR)$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR) bonus

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(DIRS):
	$(MKDIR) "$@"

clean:
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OUT_DIR)$(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
