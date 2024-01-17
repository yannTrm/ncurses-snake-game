#include "entity.h"
#include <ncurses.h>

#define SIZE_SNAKE 128  // max size

typedef enum Direction { NORTH, EAST, SOUTH, WEST } Direction;

typedef struct {
    bool life;
    bool status;
    int right;
    int bottom;
    int length;
    Entity food;
    Entity snake[SIZE_SNAKE];
    Entity tail;
    Direction direction;
} Game;

void ctor_game(Game *, WINDOW *,int, int,int);  //longueur et dimensions fenetre
void run(Game *, WINDOW *, long); // temps entre chaque deplacement
