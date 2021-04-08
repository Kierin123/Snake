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


int speed_time = 20000;
int fruitx, fruity;
int score;
int gameover = 0;
static char last_char;
static int x, y;
time_t before, now;



void keyboard_init(void);

int kbhit(void);



void Setup();

void Draw();

int input();

void logic(int ctr_flag);






#endif