# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 11:30:09 by mlecherb          #+#    #+#              #
#    Updated: 2022/01/18 15:34:48 by mlecherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

OBJ		= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

SRCS	= main.c utils/affichage.c utils/atoi.c utils/help_main.c utils/split.c \
			utils/ft_lst/lst_utils.c utils/ft_lst/lst_utils2.c sorting/log.c \
			sorting/chunk.c sorting/building_b.c rules/pa_pb.c rules/ra_rb.c \
			rules/rra_rrb.c sorting/tri_b.c 

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ) 

fclean: 	clean
			rm -f $(NAME)

norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS) ${LIB}

re:			fclean all

.PHONY :	all clean fclean re

