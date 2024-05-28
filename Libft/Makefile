# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 22:59:06 by laprieur          #+#    #+#              #
#    Updated: 2024/05/28 12:01:33 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	mandatory/ft_atoi.c						\
					mandatory/ft_bzero.c					\
					mandatory/ft_calloc.c					\
					mandatory/ft_isalnum.c					\
					mandatory/ft_isalpha.c					\
					mandatory/ft_isascii.c					\
					mandatory/ft_isdigit.c					\
					mandatory/ft_isprint.c					\
					mandatory/ft_itoa.c						\
					mandatory/ft_memchr.c					\
					mandatory/ft_memcmp.c					\
					mandatory/ft_memcpy.c					\
					mandatory/ft_memmove.c					\
					mandatory/ft_memset.c					\
					mandatory/ft_putchar_fd.c				\
					mandatory/ft_putendl_fd.c				\
					mandatory/ft_putnbr_fd.c				\
					mandatory/ft_putstr_fd.c				\
					mandatory/ft_split.c					\
					mandatory/ft_strchr.c					\
					mandatory/ft_strdup.c					\
					mandatory/ft_striteri.c					\
					mandatory/ft_strjoin.c					\
					mandatory/ft_strlcat.c					\
					mandatory/ft_strlcpy.c					\
					mandatory/ft_strlen.c					\
					mandatory/ft_strmapi.c					\
					mandatory/ft_strncmp.c					\
					mandatory/ft_strnstr.c					\
					mandatory/ft_strrchr.c					\
					mandatory/ft_strtrim.c					\
					mandatory/ft_substr.c					\
					mandatory/ft_tolower.c					\
					mandatory/ft_toupper.c					\

BONUS			:=	bonus/ft_lstadd_back.c					\
					bonus/ft_lstadd_front.c					\
					bonus/ft_lstclear.c						\
					bonus/ft_lstdelone.c					\
					bonus/ft_lstiter.c						\
					bonus/ft_lstlast.c						\
					bonus/ft_lstmap.c						\
					bonus/ft_lstnew.c						\
					bonus/ft_lstsize.c						\

ADD-ONS			:=	add-ons/ft_atol.c						\
					get_next_line/mandatory/get_next_line.c	\

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
B_OBJS			:=	$(BONUS:%.c=.build/%.o)
AO_OBJS			:=	$(ADD-ONS:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d) $(B_OBJS:%.o=%.d) $(AO_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Ofast
CPPFLAGS		:=	-MP -MMD -Iinclude
LDFLAGS			:=

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(M_OBJS) $(B_OBJS) $(AO_OBJS) $(OBJS)
	ar -rc $(NAME) $(M_OBJS) $(B_OBJS) $(AO_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: $(B_OBJS)
	ar -rc $(NAME) $(B_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"
	
add-ons: $(AO_OBJS)
	ar -rc $(NAME) $(AO_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

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
	@echo "		 _     _ _      __ _		"
	@echo "		| |   (_) |__  / _| |_		"
	@echo "		| |   | |  _ \| |_| __|		"
	@echo "		| |___| | |_) |  _| |_ 		"
	@echo "		|_____|_|____/|_|  \__|		"
	@echo "		      by laprieur           "
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
