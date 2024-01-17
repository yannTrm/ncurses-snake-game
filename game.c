#include "game.h"
#include <stdlib.h>
#include <unistd.h>


static void init_borders(Game *game, int w, int h)
{
    game->right = w - 1;
    game->bottom = h - 1;
}
static void init_food(Game *game, int x, int y)
{
    game->food.x = x;
    game->food.y = y;
}
static void init_snake(Game *game, WINDOW *win, int x, int y)
{
    mvwprintw(win,1,1, "longueur du snake : %d", game->length);

    game->snake[0].x = x;
    game->snake[0].y = y;  // head snake
    
    for (int i = 1; i < game->length; i++){
        y++;
        game->snake[i].x = x;  // body snake
        game->snake[i].y = y;
    }
}

static void get_inputs(Game *game, WINDOW *win){
    int ch = wgetch(win);
    switch (ch){
        case KEY_UP:
            game->direction = NORTH;
            break;
        case KEY_RIGHT:
            game->direction = EAST;
            break;
        case KEY_LEFT:
            game->direction = WEST;
            break;
        case KEY_DOWN:
            game->direction = SOUTH;
            break;
        case 'q':
            game->life = false;
            break;
        default:
            break;
    }
}

static void generate_food(Game *game, WINDOW *win){
    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
    srand( time( NULL ) );
    mvwprintw(win, game->food.x, game->food.y, "" );
    game->food.x = 1 + rand() % 21;
    game->food.y = 1 + rand() % 71;
}

static void update_snake(Game *game, WINDOW *win){
    game->tail.x = game->snake[game->length -1].x;
    game->tail.y = game->snake[game->length -1].y;
    for (int i = game->length - 1; i > 0 ; i--){  // pour le body
        game->snake[i].x = game->snake[i -1].x;
        game->snake[i].y = game->snake[i -1].y;
    }
    if (game->direction == NORTH) game->snake[0].x--;
    else if (game->direction == WEST) game->snake[0].y--;
    else if (game->direction == SOUTH) game->snake[0].x++;
    else if (game->direction == EAST) game->snake[0].y++;

}

static void eat_food(Game *game, WINDOW *win){
    if (game->snake[0].x == game->food.x && game->snake[0].y == game->food.y){
        game->snake[game->length].x = game->tail.x;
        game->snake[game->length].y = game->tail.y;
        game->length++;
        generate_food(game,win);
    }
    if (game->length == SIZE_SNAKE){
        game->status = true;
        game->life = false;
    }
   
}

static void check_endgame(Game *game, WINDOW *win){
    if (game->snake[0].y <= 0 || game->snake[0].x <= 0 ){
        game->life = false;
    }else if (game->snake[0].y >= game->right || game->snake[0].x >= game->bottom ){
        game->life = false;
    }
}

static void render(Game *game, WINDOW *win){
    werase(win);
    mvwprintw(win,1,1, "longueur du snake : %d", game->length);
    box(win,0,0);
    wattron(win,COLOR_PAIR(2));
    mvwprintw(win, game->food.x, game->food.y, " " ); //food
    wattroff(win,COLOR_PAIR(2));
    wattron(win,COLOR_PAIR(1));
    for (int i = 0; i < game->length; i++){
        mvwprintw(win, game->snake[i].x, game->snake[i].y, " " ); //snake body
    }
    wattroff(win,COLOR_PAIR(1));
    wrefresh(win);
}

void run(Game *game, WINDOW *win, long time){
    while(game->life)
    {
        get_inputs(game,win);
        update_snake(game, win);
        eat_food(game,win);
        render(game,win);
        check_endgame(game,win);
        usleep(time);
    }
}


void ctor_game(Game *game, WINDOW *win, int length, int w, int h)
{
    game->life = true; // par defaut vivant
    game-> status = false; // défaite jusqu'a ce qu'on gagne ( coupable jusqu'a preuve du contraire ahahahah)
    game->direction = WEST;
    game->length = length;
    init_borders(game,w,h);
    init_food(game,10,10);
    init_snake(game,win,10,50);
}