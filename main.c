#include <stdio.h>

#include "lib/Snake.h"









int main(void)
{
    srand(time(NULL));

    static int flag;
    before = clock();

    Setup();
    while (!gameover)
    {

        Draw();
        flag = input();
        logic(flag);
    }
    system("clear");
    return 0;
}