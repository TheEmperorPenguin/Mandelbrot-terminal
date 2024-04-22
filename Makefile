NAME		=	mandelbrot

SRC_DIR		=	./srcs
SRC			=	main.c		

OBJ_DIR		=	./obj

OBJ			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

CC			=	gcc

CFLAGS		=	-lncursesw -lm 

all: $(OBJ_DIR) $(NAME)
	clear

$(OBJ_DIR):
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

commit:
	@make fclean --no-print-directory
	@git add *
	@printf "Commit message: "
	@read MESSAGE; \
	git commit -m "$$MESSAGE"

push:
	git push

fpush: commit push

work:
	@git pull
	@code .
	@make


.PHONY: all clean fclean re
