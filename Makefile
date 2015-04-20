NAME = fdf

SRC = main.c \
	  get_next_line.c \

OBJ			=	$(SRC:.c=.o)

INC			=	-I./include -I./libft/include
LINK		=	-Llibft -lft $(LDFLAGS) $(MLXFLAGS)

CFLAGS		=	-Wall -Wextra -Werror -g3 -pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments
LDFLAGS		=	-L/usr/X11/lib
MLXFLAGS	=	-L $(INC_MLX) -lmlx -framework OpenGL -framework AppKit	
FLAGS		=	$(CFLAGS) $(MLXFLAGS) $(LDFLAGS)
INC_MLX		=	minilibx_macos

CC			=	/usr/bin/gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	make -C ./libft
	make -C minilibx_macos
	$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean		:	clean
	make -C ./libft fclean
	$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
