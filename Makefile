# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 11:58:48 by qgilbert          #+#    #+#              #
#    Updated: 2019/06/09 11:58:50 by qgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = one.c ft_itoa_ll.c ft_int_base.c flag_check.c \
	print_str.c print_num.c format_check.c print_d.c \
	print_c_u.c print_o_x.c print_f.c str_format.c

OMAKE = *.o

HEAD = ./head

LIBFT = libft/

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc -c $(SRC) -I$(HEAD) -Wall -Wextra -Werror 
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OMAKE)

clean:
	@/bin/rm -f $(OMAKE)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make -C $(LIBFT) fclean

re: fclean all

alah: 
	@make -C $(LIBFT)
	@gcc $(SRC) main.c -I $(HEAD)  -o $(NAME) -L. libft/libft.a #-Wall -Wextra -Werror
	#@gcc  -g $(SRC) main.c -I $(HEAD)  -o $(NAME) -L. libft/libft.a #-Wall -Wextra -Werror

rea: fclean alah
