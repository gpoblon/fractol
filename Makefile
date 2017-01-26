
NAME		=	fractol

SRC_PATH	=	srcs

SRC_NAME	= 	main.c \
				event_mouse.c \
				draw_fractal.c \
				init_fractal.c \
				compute_fractal.c \
				draw_fractal.c \
				event_keyboard.c \
				color.c \
				event_color.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

OBJ_PATH	=	./objs
LFT_PATH	=	./libft
INC_PATH	=	./includes
MLX_PATH	=

CC			=	gcc -g
CFLAGS		=	-Werror -Wextra -Wall
LDFLAGS		=	-lft -lmlx -lm -lpthread -L$(LFT_PATH)

UNAME		:=	$(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_PATH	+=	minilibx_macos
	LDFLAGS		+=	-L./minilibx_macos -framework AppKit -framework OpenGL
	CFLAGS		+=	-I./minilibx_macos
endif

ifeq ($(UNAME),Linux)
	MLX_PATH	+=	minilibx_linux
	LDFLAGS		+=	-L./minilibx_linux -lX11 -lXext
	CFLAGS		+=	-I./minilibx_linux
endif

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	-make -C $(MLX_PATH)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INC_PATH) -I$(LFT_PATH)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -fv $(NAME)
	make -C $(LFT_PATH) fclean

re:	fclean all

 .PHONY: all, clean, fclean, re
