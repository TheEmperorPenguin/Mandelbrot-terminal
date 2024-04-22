#include <ncurses.h>
#include <math.h>
#define ITER 42
int mandelbrot(double x, double y) {
    double z_real = 0, z_imag = 0;
    double c_real = x, c_imag = y;
    int iteration = 0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iteration < ITER) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = temp;
        iteration++;
    }
    if (iteration == ITER) return 0;
    return (iteration);
}
float x_pos,y_pos = 0;
float zoom = 1;
void draw()
{
        int x, y;
    getmaxyx(stdscr, y, x);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int result = mandelbrot((((double)i - (double)x / 2.) * (4. / (double)x)) * zoom + x_pos, y_pos + zoom * ((double)j - (double)y / 2.) * (4. / (double)y * ((2.5 * 9.) / 16.)));

            if (result == 0)
                attron(COLOR_PAIR(1));
            else if (result % 7 == 1)
                attron(COLOR_PAIR(2));
            else if (result % 7 == 2)
                attron(COLOR_PAIR(3));
            else if (result % 7 == 3)
                attron(COLOR_PAIR(4));
            else if (result % 7 == 4)
                attron(COLOR_PAIR(5));
            else if (result % 7 == 5)
                attron(COLOR_PAIR(6));
            else
                attron(COLOR_PAIR(7));
            if (result == 0)
                mvprintw(j, i, "#");
            else
                mvprintw(j, i, " ");

            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attroff(COLOR_PAIR(7));
        }
    }

    refresh();
}
int main(void) {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);   // Inside Mandelbrot set
    init_pair(2, COLOR_BLACK, COLOR_BLUE);    // Deep blue
    init_pair(3, COLOR_BLACK, COLOR_CYAN);    // Cyan
    init_pair(4, COLOR_BLACK, COLOR_GREEN);   // Green
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);  // Yellow
    init_pair(6, COLOR_BLACK, COLOR_RED);     // Red
    init_pair(7, COLOR_BLACK, COLOR_MAGENTA); // Magenta
    draw();
    while (1)
    {
        int ch = getch();
        switch (ch) {
            case 'w':
                y_pos -= 0.15 * zoom;
                break;
            case 's':
                y_pos += 0.15 * zoom;
                break;
            case 'a':
                x_pos -= 0.15 * zoom;
                break;
            case 'd':
                x_pos += 0.15 * zoom;
                break;
            case 'q':
                zoom *= 0.9;
                break;
            case 'e':
                zoom /= 0.9;
                break;
            case ' ':
                endwin();
                return 0;
                break;
        }
        draw();
    }
    return 0;
}
