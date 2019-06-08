NAME = libftprintf.a

SRC = one.c ft_itoa_ll.c ft_int_base.c flag_check.c \
	print_str.c print_num.c

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
	@rm -f $(OMAKE)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

alah: 
	@make -C $(LIBFT)
	@gcc  -g $(SRC) main.c -I $(HEAD)  -o $(NAME) -L. libft/libft.a #-Wall -Wextra -Werror

rea: fclean alah
