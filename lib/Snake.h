#ifndef SNAKE_H
#define SNAKE_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAP_HIGH 15
#define MAP_WIDTH 30


int speed_time = 20000;     // Speed tiem variable - used to control speed of the game
int fruitx, fruity;         // Posiotion of the fruit x, y 
int score;          
int gameover = 0;           
static int x, y;            // x, y position of the snake
time_t before, now;         // variables used to create delay in function logic() - speed of the game



void keyboard_init(void);

int kbhit(void);



void Setup();

void Draw();

int input();

void logic(int ctr_flag);






#endif