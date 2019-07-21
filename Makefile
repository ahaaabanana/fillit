# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 16:30:59 by vtouffet          #+#    #+#              #
#    Updated: 2019/07/21 13:35:54 by tgrandpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME): 
	gcc -c $(NAME).c
	gcc -o $(NAME) $(NAME).o -L. libft/libft.a
	
clean:
	/bin/rm -rf $(NAME).o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
