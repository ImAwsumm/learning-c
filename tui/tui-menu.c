#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 5

int main() 
{
	// startup ncurses
    	initscr();
    	cbreak();
    	noecho();
    	keypad(stdscr, TRUE);
    	curs_set(0);

    	// Menu items
    	char *menu_choices[MAX_ITEMS] = 
    	{
		"Option 1",
    	        "Choice B",
    	        "Number Three", 
    	        "Fourth Choice",
    	        "Last option (exit)"
    	};

    	int highlighted = 0;
    	int choice = -1;
    	int c;

    	// Main menu loop
    	while(1) 
	{
		clear();

    	        attron(A_BOLD);
    	        mvprintw(2, (COLS - strlen("menu")) / 2, "menu"); // set title
    	        attroff(A_BOLD);
   		// items 
    	        for (int i = 0; i < MAX_ITEMS; i++) 
    	        {
    	            	if (i == highlighted)
    	                	attron(A_REVERSE);
    	            
    	            	mvprintw(4 + i, (COLS - strlen(menu_choices[i])) / 2, menu_choices[i]);
    	            
    	            	if (i == highlighted)
    	                	attroff(A_REVERSE);
    	        }
    	        // wait for imput 
    	        c = getch();

    	        switch(c) 
    	        {
    	            case KEY_UP:
    	                highlighted--;
    	                if (highlighted < 0)
    	                    highlighted = MAX_ITEMS - 1;
    	                break;
    	            case KEY_DOWN:
    	                highlighted++;
    	                if (highlighted >= MAX_ITEMS)
    	                    highlighted = 0;
    	                break;
    	            case 10:  // enter key
    	                choice = highlighted;
    	                break;

    	        }
   
    	        // action when menu option is chosen
    	        if (choice != -1) 
    	        {
    	            	switch(choice) 
    	            	{
		    	        case 0:
		    	    	    clear();
		    	    	    printw("\nInstall dotfiles\n");
		    	    	    break;
		    	        case 1:
		    	    	    mvprintw(LINES-2, 0, "Plan B");
		    	    	    break;
    	            	        case 2:
		    	    	    mvprintw(LINES-2, 0, "Number three");
    	            	        break;
    	            	        case 3:
    	            	            mvprintw(LINES-2, 0, "Fourth option");
    	            	        break;
    	            	        case 4:
    	            	    	       endwin();
    	            		       return 0;
    	            	}
    	            	refresh();
    	            	getch();
    	            	choice = -1;
		}
		refresh();
	}
	endwin();
	return 0;
}
