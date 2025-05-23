# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:34:19 by mlaffita          #+#    #+#              #
#    Updated: 2025/03/07 17:45:48 by mlaffita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nom de l'executable
NAME = push_swap

# Source and object diretories
SRCDIR = src
OBJDIR = obj

# Librairies
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
INCLUDE = -I include

RM = rm -f 

vpath %.c \
	$(SRCDIR) \
	$(SRCDIR)/parsing \
	$(SRCDIR)/sort \
	$(SRCDIR)/moves

# Sources and object files
SRC = main.c utils.c input_check.c stack.c mv_rot.c mv_rev_rot.c mv_swap.c mv_push.c mv_combined.c small_sort.c big_sort.c free_all.c
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) all -C $(PRINTFDIR)
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

# Rule to clean up object files	
clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)
		@rm -rf $(OBJDIR)

#Rule to clean  up object files and the library
fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFTDIR)
		$(MAKE) fclean -C $(PRINTFDIR)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re