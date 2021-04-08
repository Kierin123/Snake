#include "Snake.h"

void keyboard_init(void)
{
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 40;
    tcsetattr(0, TCSANOW, &info);
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void Draw()
{
    system("clear");
    for (int i = 0; i <= MAP_HIGH; i++)
    {
        for (int j = 0; j <= MAP_WIDTH; j++)
        {
            if (i == 0 || i == MAP_HIGH || (j == 0) || (j == MAP_WIDTH))
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("@");
                }
                else if (i == fruitx && j == fruity)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Wynik: %d\n", score);
}

void Setup()
{
    gameover = 0;
    x = MAP_HIGH / 2;
    y = MAP_WIDTH / 2;
    fruitx = rand() % MAP_HIGH + 1;
    fruity = rand() % MAP_WIDTH + 1;
    while (fruitx <= 0 || fruitx >= MAP_HIGH)
    {
        fruitx = rand() % MAP_HIGH + 1;
    }
    while (fruity <= 0 || fruity >= MAP_WIDTH)
    {
        fruity = rand() % MAP_WIDTH + 1;
    }
    score = 0;
}

int input()
{
    static int f;
    if (kbhit())
    {
        static char key;
        scanf("%c", &key);

        switch (key)
        {
        case 'a':
            f = 1;
            return f;
            break;

        case 'd':
            f = 2;
            return f;
            break;
        case 'w':
            f = 3;
            return f;
            break;
        case 's':
            f = 4;
            return f;
            break;

        case 'x':
            gameover = 1;
            return 0;
            break;
        }
    }

    return f;
}

void logic(int ctr_flag)
{

    now = clock();
    clock_t t = now - before;
    if (t > speed_time)
    {
        switch (ctr_flag)
        {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;

        default:
            break;
        }
        before = now;
    }
    if (x <= 0 || y <= 0 || y >= MAP_WIDTH || x >= MAP_HIGH)
    {
        gameover = 1;
    }
    if (x == fruitx && y == fruity)
    {

        fruitx = rand() % MAP_HIGH + 1;
        fruity = rand() % MAP_WIDTH + 1;

        while (fruitx <= 0 || fruitx >= MAP_HIGH)
        {
            fruitx = rand() % MAP_HIGH + 1;
        }
        while (fruity <= 0 || fruity >= MAP_WIDTH)
        {
            fruity = rand() % MAP_WIDTH + 1;
        }

        score += 10;

        if ((score % 3 == 0))
        {
            speed_time -= 2500;
        }
    }
}