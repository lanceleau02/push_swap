# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 15:57:58 by laprieur          #+#    #+#              #
#    Updated: 2024/05/28 11:12:29 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_NAME		:=	push_swap
B_NAME		:=	checker

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

LIBFT		:=	libft/libft.a

MANDATORY	:=	mandatory/algorithms.c			\
				mandatory/algorithms_utils.c	\
				mandatory/double_operations.c	\
				mandatory/error_cases.c			\
				mandatory/main.c				\
				mandatory/manage_index.c		\
				mandatory/manage_list.c			\
				mandatory/manage_tab.c			\
				mandatory/memory.c				\
				mandatory/operations.c			\
				mandatory/parsing.c				\
				mandatory/push_swap.c			\
				mandatory/push_swap_utils.c		\
				mandatory/smart_rotate.c		\
				mandatory/sort.c				\
				mandatory/sort_utils.c			\

BONUS		:=	bonus/apply_operations.c		\
				bonus/checker.c					\
				bonus/main.c					\

M_OBJS		:=	$(MANDATORY:%.c=.build/%.o)
B_OBJ		:=	$(BONUS:%.c=.build/%.o)
DEPS		:=	$(M_OBJS:%.o=%.d) $(B_OBJ:%.o=%.d)

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	-MP -MMD -Iinclude -Iinclude/push_swap.h -ILibft/include/libft.h
LDFLAGS		:=	-LLibft -lft

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS	+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(M_NAME)

bonus: header $(B_NAME)

$(M_NAME): $(LIBFT) $(M_OBJS)
	$(CC) $(CFLAGS) $(M_OBJS) $(LDFLAGS) -o $(M_NAME)
	$(info CREATED $(M_NAME))

$(B_NAME): M_OBJS	:=	$(filter-out .build/mandatory/main.o,$(M_OBJS))

$(B_NAME): $(LIBFT) $(B_OBJ) $(M_OBJS)
	$(CC) $(CFLAGS) $(B_OBJ) $(M_OBJS) $(LDFLAGS) -o $(B_NAME)
	$(info CREATED $(B_NAME))

$(LIBFT):
	$(MAKE) -C Libft

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(MAKE) -C Libft clean
	rm -rf .build

fclean: clean
	$(MAKE) -C Libft fclean
	rm -rf $(M_NAME)
	rm -rf $(B_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "			 _											"
	@echo "	 ____  _   _ ___| |__      _____      ______ ____ 	"
	@echo "	|  _ \| | | / __|  _ \    / __\ \ /\ / / _  |  _ \	"
	@echo "	| |_) | |_| \__ \ | | |   \__ \  V  V / (_| | |_) |	"
	@echo "	|  __/ \____|___/_| |_|___|___/ \_/\_/ \____|  __/	"
	@echo "	|_|                  |_____| by laprieur    |_|		"
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR: