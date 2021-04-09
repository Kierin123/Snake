#include <stdio.h>
#include "snake/Snake.h"

/*
 * ############ Snake ############ 
 * Created by Marcin Kierinkiewicz 
 */

int main(void)
{
   
    static int flag;
    snake S1;
    
    Setup(&S1);
    while (!check_game())
    {

        Draw(S1);
        flag = input();
        logic(flag, &S1);
    }
    system("clear");
    return 0;
}