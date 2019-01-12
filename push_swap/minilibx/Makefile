#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
FLAGS+=-O2

all: $(NOM)

%.o: %.c
	@cc $(FLAGS) -o $@ -c $<
	@printf "\33[2K  ➡ %-20s%s\r" "$<" "✅"

%.o: %.m
	@cc $(FLAGS) -o $@ -c $<
	@printf "\33[2K  ➡ %-20s%s\r" "$<" "✅"

$(NOM):	$(OBJ)
	@ar rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "\33[2K \r\nMLX's done !\n"

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
