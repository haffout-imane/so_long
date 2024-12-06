NAME = so_long

NAME2 = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit 

SRCS = ./mandatory/main.c ./mandatory/so_long.c \
       ./mandatory/check1.c ./mandatory/check2.c ./mandatory/moves.c ./mandatory/image.c \
       ./mandatory/errors.c ./mandatory/utils.c ./mandatory/utils1.c  ./mandatory/utils2.c\

SRCS2 = ./bonus/main_bonus.c ./bonus/so_long_bonus.c \
    	./bonus/check1_bonus.c ./bonus/check2_bonus.c ./bonus/image_bonus.c \
		./bonus/animation_bonus.c ./bonus/moves_player_bonus.c ./bonus/moves_enemy_bonus.c \
    	./bonus/errors_bonus.c ./bonus/utils_bonus.c ./bonus/utils1_bonus.c  ./bonus/utils2_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

all: $(NAME)
bonus: $(NAME2)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAGS)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2) $(MLXFLAGS)


%.o: %.c ./mandatory/so_long.h ./bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY : all clean fclean re