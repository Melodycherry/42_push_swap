# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:34:19 by mlaffita          #+#    #+#              #
#    Updated: 2025/02/05 20:03:08 by mlaffita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCDIR = src
OBJDIR = $(SRCDIR)

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

SRC = main.c

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = gcc

INCLUDE = -I include

RM = rm -f 

CFLAGS = -g3 -Wall -Wextra -Werror

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) all -C $(PRINTFDIR)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
		
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)
fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFTDIR)
		$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re