# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:33:22 by swaegene          #+#    #+#              #
#    Updated: 2022/03/24 14:32:58 by swaegene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

FT_PRINTF = libftprintf.a
LIBFT = libft.a

MKDIR = mkdir
RM = rm -f
AR = ar rsu
CP = cp
MV = mv

SRC_DIR = ./src/
INC_DIR = ./include/
FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF_INC_DIR = $(FT_PRINTF_DIR)include/
LIBFT_DIR = ./libft/

ifdef MAKE_DEBUG
OUT_DIR = ./debug/
NAME := $(OUT_DIR)$(NAME)
SERVER := $(OUT_DIR)$(SERVER)
CLIENT := $(OUT_DIR)$(CLIENT)
DIRS = $(OUT_DIR)
CFLAGS = -g3 -fsanitize=address
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Werror -Wextra
CPPFLAGS += -I$(INC_DIR) -I$(FT_PRINTF_INC_DIR) -I$(LIBFT_DIR) -MD
LDFLAGS += -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

CLIENT_SRCS = client.c bits.c
SERVER_SRCS = server.c bits.c utils.c
CLIENT_OBJS = $(addprefix $(OUT_DIR),$(CLIENT_SRCS:%.c=%.o))
SERVER_OBJS = $(addprefix $(OUT_DIR),$(SERVER_SRCS:%.c=%.o))
CLIENT_DEPS = $(addprefix $(OUT_DIR),$(CLIENT_SRCS:%.c=%.d))
SERVER_DEPS = $(addprefix $(OUT_DIR),$(SERVER_SRCS:%.c=%.d))

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(DIRS) $(CLIENT_OBJS) $(FT_PRINTF_DIR)$(FT_PRINTF) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LDFLAGS) -o $@

$(SERVER): $(DIRS) $(SERVER_OBJS) $(FT_PRINTF_DIR)$(FT_PRINTF) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LDFLAGS) -o $@

all: $(NAME)

bonus: $(NAME)

$(FT_PRINTF_DIR)$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(DIRS):
	$(MKDIR) "$@"

clean:
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(SERVER_DEPS)
	$(RM) $(CLIENT_DEPS)

fclean: clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)

re: fclean all

.PHONY: all bonus clean fclean re
