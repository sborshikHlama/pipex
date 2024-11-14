NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		ft_libft/ft_libft.a\


$(NAME) :
	make all -C ft_libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_libft

clean :
	$(RM) $(NAME)
	make clean -C ft_libft

re : fclean all

bonus : clean
	make all -C ft_libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)