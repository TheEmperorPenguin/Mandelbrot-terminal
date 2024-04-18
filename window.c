#include <ncurses.h>
#include <math.h>

double mandelbrot(double x, double y) {
    double z_real = 0, z_imag = 0;
    double c_real = x, c_imag = y;
    int iteration = 0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iteration < 42) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = temp;
        iteration++;
    }
    if (iteration == 42) return 0;
    return (iteration - log(log(sqrt(z_real * z_real + z_imag * z_imag))) / log(2));
}

int main(int argc, char **argv) {
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

    int x, y;
    getmaxyx(stdscr, y, x);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            double result = mandelbrot((((double)i - (double)x / 2.) * (4. / (double)x)), ((double)j - (double)y / 2.) * (4. / (double)y));

            if (result == 0)
                attron(COLOR_PAIR(1));
            else if (result < 5)
                attron(COLOR_PAIR(2));
            else if (result < 10)
                attron(COLOR_PAIR(3));
            else if (result < 15)
                attron(COLOR_PAIR(4));
            else if (result < 20)
                attron(COLOR_PAIR(5));
            else if (result < 25)
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
    getch();
    endwin();
    return 0;
}
