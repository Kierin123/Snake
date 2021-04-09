#ifndef SNAKE_H
#define SNAKE_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAP_HIGH 10
#define MAP_WIDTH 10
#define START_GAME_SPEED 20000


static int speed_time = START_GAME_SPEED;     // Speed tiem variable - used to control speed of the game
static int fruitx, fruity;         // Posiotion of the fruit x, y 
static int score;          
 int gameover = 0;     

typedef struct point
{
    int x;
    int y;
} point;

typedef struct snake
{
    int length;
    point snake_tail[32];

} snake;

static int x, y;            // x, y position of the snake
static time_t before, now;         // variables used to create delay in function logic() - speed of the game



static void keyboard_init(void);
static int kbhit(void);
static void generate_fruit();
static void tail_create(snake *SN);



void Setup(snake *SN);
void Draw(snake SN);
int input();
void logic(int ctr_flag, snake *SN);
int check_game();






#endif