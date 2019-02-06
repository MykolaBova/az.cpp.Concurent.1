#include <curses.h>

extern NCURSES_EXPORT_VAR(WINDOW *) stdscr;

int main()
{
    initscr();			/* Start curses mode 		  */

    //printw("Hello World !!!");	/* Print Hello World		  */
    mvwprintw(stdscr, 3, 0, "*** Multiple Code Dates ***");

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}