#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#define DELAY 50

int main() {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    int y = maxY - 2; // Initial position of the character
    int x = maxX / 2; // Middle of the screen
    int ox = maxX - 2;
    int jump = 0; // To control the jump
    int jumpHeight = 7; // The height of the jump
    int isJumping = 0; // Flag to indicate if the character is jumping
    timeout(25);
    while (1) {
        clear();
        if(y == maxY - 2 && x == ox)
            break;
        mvprintw(y, x, "O");
        mvprintw(maxY - 2, ox, "Δ");
        for (int i = 0; i < maxX; i++) {
            mvprintw(maxY - 1, i, "‾");
        }
        refresh();

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (!isJumping) {
                    isJumping = 1;
                    jump = jumpHeight;
                }
                break;
            case KEY_LEFT:
                if (x - 1 >= 0) {
                    x -= 1;
                }
                break;
            case KEY_RIGHT:
                if (x + 1 < maxX) {
                    x += 1;
                }
                break;
            case 'q':
                endwin();
                return 0;
        }

        if (isJumping) {
            y -= 1;
            jump--;
            if (jump <= 0) {
                isJumping = 0;
            }
        } else {
            if (y < maxY - 2) {
                y++;
            }
        }
        ox--;
        if (ox < 0)
            ox = maxX - 2;
        usleep(DELAY);
    }
    while(1){
        int ch = getch();
        mvprintw(maxY / 2, maxX / 2, "^DEAD^");
        refresh();
        switch (ch) {
            case 'q':
                endwin();
                return 0;
        }
    }
    endwin();
    return 0;
}