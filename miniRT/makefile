NAME = miniRT
cc = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
<<<<<<< HEAD
SRC =  canvas.c main.c print.c ray.c scene.c utils.c hit_sphere.c phong_lighting.c object_create.c object_utils.c normal.c hit.c hit_plane.c parse_utils.c\
	parse.c\
	get_next_line.c\
	get_next_line_utils.c\
	hit_cylinder.c\
	parse_utils.c\
	init_object.c\
	init_acl.c
=======
SRC =  canvas.c main.c print.c ray.c scene.c utils.c hit_sphere.c phong_lighting.c object_create.c object_utils.c normal.c hit.c hit_plane.c hit_cylinder.c rotate.c
>>>>>>> 0febcd0df08b05a577c58b0d6614b327845ab038
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft/
LIB = $(LIBFT_DIR)libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
			$(CC) $(CFLAGS) $(MLXFLAG) -o $@ $^
$(LIB) :
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf  $(OBJ)

fclean:
	make clean
	rm -rf $(LIB)
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re