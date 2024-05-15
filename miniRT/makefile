NAME = miniRT
cc = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
SRC =  canvas.c main.c print.c ray.c scene.c utils.c hit_sphere.c phong_lighting.c object_create.c object_utils.c normal.c hit.c hit_plane.c hit_cylinder.c rotate.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
				$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $@

clean:
	rm -rf  $(OBJ)

fclean: 
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: 
	make fclean ;\
	make all

.PHONY: all clean fclean re