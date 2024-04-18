#include <ncurses.h>
#include <stdlib.h>

int main() {
    int choice = 1;
    int ch;
	int x = 0;
	int y = 0;
	int height, width;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
	printw("Select an option:");
	do
	{
        switch(ch) {
            case KEY_UP:
                if(choice > 1) {
                    choice--;
                }
                break;
            case KEY_DOWN:
                if(choice < 4) {
                    choice++;
                }
                break;
        }

        // Clear the previous selection
        attron(A_DIM);
        switch(choice) {
            case 1:
                mvprintw(3, 0, "2. Option 2");
                mvprintw(4, 0, "3. Option 3");
                mvprintw(5, 0, "4. Exit");
                break;
            case 2:
                mvprintw(2, 0, "1. Option 1");
                mvprintw(4, 0, "3. Option 3");
                mvprintw(5, 0, "4. Exit");
                break;
            case 3:
                mvprintw(2, 0, "1. Option 1");
                mvprintw(3, 0, "2. Option 2");
                mvprintw(5, 0, "4. Exit");
                break;
            case 4:
                mvprintw(2, 0, "1. Option 1");
                mvprintw(3, 0, "2. Option 2");
                mvprintw(4, 0, "3. Option 3");
                break;
        }
        attroff(A_DIM);

        // Highlight the current selection
		attron(A_UNDERLINE);
        switch(choice) {
            case 1:
                mvprintw(2, 0, "1. Option 1");
                break;
            case 2:
                mvprintw(3, 0, "2. Option 2");
                break;
            case 3:
                mvprintw(4, 0, "3. Option 3");
                break;
            case 4:
                mvprintw(5, 0, "4. Exit");
                break;
        }
		attroff(A_UNDERLINE);
        
		refresh();
    } while((ch = getch()) != 10); // 10 is the ASCII code for Enter key

    switch(choice) {
        case 1:
            mvprintw(7, 0, "You selected Option 1\n");
            break;
        case 2:
            mvprintw(7, 0, "You selected Option 2\n");
            break;
        case 3:
            mvprintw(7, 0, "You selected Option 3\n");
            break;
        case 4:
            mvprintw(7, 0, "Exiting the program...\n");
            return 0;
    }

	do
	{
		getmaxyx(stdscr, height, width);
		if (x > width)
				x = width - 1;
		if (y > height)
				y = height - 1;
        mvprintw(y, x, "@");
		curs_set(0);
		clear();
        switch(ch) {
            case KEY_LEFT:
                if(x - 1 >= 0) {
                    x--;
				}
                break;
            case KEY_RIGHT:
                if(x + 1 < width) {
                    x++;
                }
                break;
			case KEY_UP:
               if(y - 1 >= 0) {
                    y--;
				}
                break;
            case KEY_DOWN:
                if(y + 1 < height) {
                    y++;
                }
                break;
		}
        mvprintw(y, x, "@");
		refresh();

	}while ((ch = getch()) != 'q');
    endwin();

    return 0;
}
