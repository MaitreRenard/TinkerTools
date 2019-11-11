#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define DELAY 10000

int main(int argc, char **argv) {
	int x = 0, y = 0;

	//Get screen size
	const struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	const int screen_width = w.ws_col - 1;
	const int screen_height = w.ws_row;

	//Init ncurses
	initscr();
	noecho();
	curs_set(FALSE);

	//Print loading bar
	mvprintw(y, x, "[");
	x++;
	while(x < screen_width) {
		mvprintw(y, x, "=");
		refresh();
		//sleep(500);
		x++;
	}
	mvprintw(y, x, "]");
	refresh();
	sleep(500);

	endwin();
	return 0;
}
