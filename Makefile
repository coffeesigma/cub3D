CC = cc -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = libft.a
HEADER = cub3d.h
HEADER_B = cube3d_bonus.h
SRCS = 
SRCS_B = 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = cub3D
MLX_DIR = ./mlx

ifdef WITH_BONUS
	HEADER = $(HEADER_B)
	SRCS = $(SRCS_B)
	OBJS = $(OBJS_B)
endif

.PHONY: all re clean fclean re bonus

all : $(NAME)

bonus : $(NAME)

.c.o : %.c $(HEADER)
	$(CC) -c $<

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	install_name_tool -change libmlx.dylib $(MLX_DIR)/libmlx.dylib $(NAME)

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	make bonus -C $(LIB_DIR)

$(MLX_DIR)/$(MLX) :
	make -C $(MLX_DIR)

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	make clean -C $(MLX_DIR)
	make fclean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)