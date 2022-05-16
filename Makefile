CC		=	gcc
NAME	=	so_long
FLAGS	=	-Wall -Wextra -Werror -g

INC		=	so_long.h
OBJ		=	objs
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	main.c				\
			ft_check_map.c		\
			ft_split.c			\
			ft_utils.c			\
			map.c				\
			exit.c				\

$(NAME): $(OBJ) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: ./%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
