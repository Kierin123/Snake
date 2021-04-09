#include "Snake.h"

static void keyboard_init(void)
{
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 40;
    tcsetattr(0, TCSANOW, &info);
}

static int kbhit(void)
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

void Draw(snake SN)
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
                //for (int k = 0; k < SN.length; k++)
                //  {
                if (i == SN.snake_tail[0].x && j == SN.snake_tail[0].y)
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
                //  }
            }
        }
        printf("\n");
    }
    printf("Wynik: %d\n", score);
}

void Setup(snake *SN)
{
    srand(time(NULL));
    gameover = 0;
    SN->length = 1;
    SN->snake_tail[0].x = MAP_HIGH / 2;
    SN->snake_tail[0].y = MAP_WIDTH / 2;

    before = clock();
    generate_fruit();
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

void tail_create(snake *SN)
{
    point temp_point;
    for (int i = 0; i < SN->length - 1; i++)
    {
        SN->snake_tail[i + 1].x = SN->snake_tail[i].x;
        SN->snake_tail[i + 1].y = SN->snake_tail[i].y;
    }
}

void logic(int ctr_flag, snake *SN)
{

    //  tail_create(SN);
    now = clock();
    clock_t t = now - before;
    if (t > speed_time)
    {
        switch (ctr_flag)
        {
        case 1:
            SN->snake_tail[0].y--;
            break;
        case 2:
            SN->snake_tail[0].y++;
            break;
        case 3:
            SN->snake_tail[0].x--;
            break;
        case 4:
            SN->snake_tail[0].x++;
            break;

        default:
            break;
        }
        before = now;
    }
    if (SN->snake_tail[0].x <= 0 || SN->snake_tail[0].y <= 0 || SN->snake_tail[0].y >= MAP_WIDTH || SN->snake_tail[0].x >= MAP_HIGH)
    {
        gameover = 1;
    }
    if (SN->snake_tail[0].x == fruitx && SN->snake_tail[0].y == fruity)
    {
        SN->length++;

        generate_fruit();

        score += 10;

        if ((score % 3 == 0))
        {
            speed_time -= 2500;
        }
    }
}

void generate_fruit()
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
}

int check_game()
{
    return gameover;
}