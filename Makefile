CC		=	gcc
NAME	=	pipex
FLAGS	=	-Wall -Wextra -Werror -g

INC		=	pipex.h
OBJ		=	objs
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	get_next_line/get_next_line.c		\
			get_next_line/get_next_line_utils.c \
			main.c

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
