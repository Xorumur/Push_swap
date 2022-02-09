# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 11:30:09 by mlecherb          #+#    #+#              #
#    Updated: 2022/02/09 16:24:13 by mlecherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

OBJ		= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address

SRCS	=	main.c utils/atoi.c utils/help_main.c utils/split.c sorting/det_case.c \
			ft_lst/lst_utils.c ft_lst/lst_utils2.c sorting/quicksort.c rules/pa_pb.c \
			rules/ra_rb.c rules/rra_rrb.c rules/sa_sb.c utils/afflst.c \
			sorting/first_step.c sorting/parting.c sorting/assist.c sorting/exception.c \
			sorting/sizetree.c sorting/push_a/push_a.c sorting/push_a/pos.c \
			sorting/push_a/pos2.c helper.c sorting/push_a/alpha.c sorting/push_a/beta.c \
			sorting/sizefive.c

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ) 

fclean: 	clean
			rm -f $(NAME)

norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS)

re:			fclean all

.PHONY :	all clean fclean re

