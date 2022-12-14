# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 07:13:36 by absalhi           #+#    #+#              #
#    Updated: 2022/12/13 04:42:49 by absalhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CNAME	=	checker

CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
RM		=	rm -rf

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

_SRCS	=	push_swap.c push_swap_utils.c stack_utils.c stack_utils_2.c \
			push_swap_errors.c push_swap_operations.c push_swap_operations_2.c \
			push_swap_operations_3.c quick_sort_stack.c sort_stack.c \
			stack_position.c push_swap_exec.c
SRCS	=	$(addprefix srcs/, $(_SRCS))
OBJS	=	$(SRCS:.c=.o)

_CSRCS	=	helpers.c
CSRCS	=	$(addprefix bonus/, $(_CSRCS))
COBJS	=	$(CSRCS:.c=.o)

.c.o	:
			@echo $(ITALIC)$(GRAY) "     - Making $<..." $(NONE)
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) srcs/main.o
			@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
			@make -C libft/
			@$(CC) $(CFLAGS) -L libft/ -lft srcs/main.o $(OBJS) -o $(NAME)
			@echo $(GREEN)"- Compiled -"$(NONE)

bonus	:	$(OBJS) $(COBJS) bonus/main.o
			@echo $(ITALIC)$(GRAY) "     - Compiling $(CNAME)..." $(NONE)
			@make -C libft/
			@$(CC) $(CFLAGS) -L libft/ -lft bonus/main.o $(OBJS) $(COBJS) -o $(CNAME)
			@echo $(GREEN)"- Compiled -"$(NONE)

clean	:
			@echo $(ITALIC)$(GRAY) "     - Removing object files..." $(NONE)
			@$(RM) $(OBJS) $(COBJS) srcs/main.o bonus/main.o
			@make clean -C libft/

fclean	:	clean
			@echo $(ITALIC)$(GRAY) "     - Removing $(NAME)/$(CNAME)..." $(NONE)
			@$(RM) $(NAME) $(CNAME)
			@make fclean -C libft/

re		:	fclean all

.PHONY	:	all clean fclean re bonus
