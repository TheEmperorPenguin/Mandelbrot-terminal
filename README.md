# Mandelbrot Visualization with Ncurses

This C project allows you to visualize the Mandelbrot Set directly in your terminal using the Ncurses library. The Mandelbrot Set is a set of complex numbers with highly intricate fractal properties. With this program, you can explore the beauty of the Mandelbrot Set right from your command line.

## Features

- Real-time visualization of the Mandelbrot Set in your terminal.
- Zoom in and out functionality to explore different regions of the set.
- Smooth movement controls to navigate through the Mandelbrot Set.
- Colorful rendering for enhanced visualization.

## Controls

- `w`: Move up.
- `s`: Move down.
- `a`: Move left.
- `d`: Move right.
- `q`: Zoom in.
- `e`: Zoom out.
- `space`: Quit the program.

## Usage

1. Compile the project using the provided Makefile.
   ```bash
   make
   ```
2. Run the executable in your terminal.
   ```bash
   ./mandelbrot
   ```
3. Use the controls mentioned above to navigate and explore the Mandelbrot Set.
4. Press `space` to quit the program.

## Requirements

- C compiler (GCC recommended)
- Ncurses library

## Installation

### Ubuntu / Debian

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

### Fedora

```bash
sudo dnf install ncurses-devel
```

## Makefile

```make
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

re: fclean allc
```

## Screenshots

![Mandelbrot Visualization](/screenshots/mandelbrot_terminal.png)

## Acknowledgments

- This project was inspired by the beauty of the Mandelbrot Set and the simplicity of Ncurses library.
- Thanks to the developers of Ncurses for providing such a powerful tool for terminal-based user interfaces.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
