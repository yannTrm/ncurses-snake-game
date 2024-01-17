#include <defs.h>
#include <proto.h>

int main(void){
    WINDOW *win = NULL;
    Game game;

    int h = 30;
    int w = 80;

    initscr(); // initialise ncurses
    curs_set(false);
    mvprintw(24, 0, "Press q to Exit");
    mvprintw(25, 0, "Press KEY_UP to go up ;)");
    mvprintw(26, 0, "Press KEY_DOWN to go down ;)");
    mvprintw(27, 0, "Press KEY_LEFT to go left ;)");
    mvprintw(28, 0, "Press KEY_RIGHT to go right ;)");
       
    refresh();
    win = create_newwin(h,w,(LINES - h)/2,(COLS - w)/2);
    keypad(win,true);
    wattron(win,A_REVERSE);
    nodelay(win,true); 
    start_color();  
    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    ctor_game(&game, win, 2, w, h); // 2 correspond to length of the snake (head + body = 2)
    run(&game, win, 100000 );
    if (game.status){ 
        printf("tu as gagné");  
    }else {
        printf("tu as perdu");
    }      
    endwin();   
}
  
 
WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;  //declare la fenetre
    local_win = newwin(height,width,starty,startx);  //creer la fenetre
    box(local_win,0,0); // affiche un contour a la fenetre
    wrefresh(local_win); // permet le reel affichage de la fnetre (refresh)
    return local_win;
}

