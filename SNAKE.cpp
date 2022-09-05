//
// Created by 33559 on 2022/9/5.
//
//
// Created by 33559 on 2022/9/4.
//
#include "SNAKE.h"
HWND hwnd = NULL;


Snake snake = {
        snake.Snake_length = 3,
        snake.Snake_way = RIGHT,
        snake.Snake_speed = 10 ,
        snake.location[0].x = 30 ,
        snake.location[0].y = 10 ,
};
/*
void Initfood()
{
    srand(GetTickCount());

    Food food{
            food.x = rand() % 640,
            food.y = rand() % 480,
            food.r = rand() %10 + 5 ,
            food.Food_color = RGB(rand() % 256,
                                  rand() % 256 ,rand() % 256 ),
            food.Food_grade = 0,
            food.flag = TRUE,
    };

    BeginBatchDraw();
    if(food.flag)
    {
        solidcircle(food.x , food.y ,food.r);
    }
    EndBatchDraw();
}*/
//直接在数据初始化哪里初始更好
/**/
Food food;

void InitData()
{
    initgraph(640, 480);

    for (int i = 0; i < snake.Snake_length; ++i)
    {
        snake.location[i].x = 40 -10 *i;
        snake.location[i].y = 10;
    }
    srand((int)time(NULL));

    food.x = rand() % 640;
    food.y = rand() % 480;
    food.r = rand() % 10 + 5 ;
    food.Food_color = RGB(rand() % 256,
                          rand() % 256 ,rand() % 256 );
    food.Food_grade = 0;
    food.flag = TRUE;

}

void KBctrl()
{
    if(_kbhit())
    {
        switch (_getch())
        {

            case 72 :
            case 'W':
            case 'w':
                if(snake.Snake_way != DOWN)
                {
                    snake.Snake_way = UP;
                }
                break;
            case 80 :
            case 's':
            case 'S':
                if(snake.Snake_way != UP)
                    snake.Snake_way = DOWN;
                break;
            case 75 :
            case 'A':
            case 'a':
                if(snake.Snake_way != RIGHT)
                    snake.Snake_way = LEFT;
                break;
            case 77 :
            case 'D':
            case 'd':
                if(snake.Snake_way != LEFT)
                    snake.Snake_way = RIGHT;
                break;
        }
    }
}
void MoveSnake()
{
    for (int i = snake.Snake_length -1 ; i > 0; i--)
    {
        snake.location[i] = snake.location[i -1];
    }
    //[i] -> [0]实现只移动蛇头
    switch (snake.Snake_way)
    {
        //每一个    UP,DOWN,LEFT,RIGHT 定义了蛇头的移动
        //这里才是调头的根本原因！
        case UP:
            snake.location[0].y -= snake.Snake_speed;
            if(snake.location[0].y <= 0)
            {
                snake.location[0].y = 480;
            }
            break;
        case DOWN:
            snake.location[0].y += snake.Snake_speed;
            if(snake.location[0].y >= 480)
            {
                snake.location[0].y = 0;
            }
            break;
        case LEFT:
            snake.location[0].x -= snake.Snake_speed;
            if(snake.location[0].x <= 0)
            {
                snake.location[0].x = 640;
            }
            break;
        case RIGHT:
            snake.location[0].x += snake.Snake_speed;
            if(snake.location[0].x >= 640)
            {
                snake.location[0].x = 0;
            }
            break;
    }

}
/**/
void EatFood()
{
    if(food.flag &&
       snake.location[0].x >= food.x - food.r&&
       snake.location[0].x <= food.x + food.r&&
       snake.location[0].y >= food.y - food.r&&
       snake.location[0].y <= food.y + food.r)
    {
        food.flag = FALSE;
        snake.Snake_length++;
    }
    if(!food.flag)
    {
        food.x = rand() % 640;
        food.y = rand() % 480;
        food.r = rand() %10 + 5 ;
        food.Food_color = RGB(184, 95, 175);
        food.Food_grade = 0;
        food.flag = TRUE;
    }
}

void Gamedraw()
{
    BeginBatchDraw();

    setbkcolor(RGB(246,153,180));
    cleardevice();
    setfillcolor(GREEN);
    for (int i = 0; i < snake.Snake_length; ++i)
    {
        solidcircle(snake.location[i].x,
                    snake.location[i].y , 5);
    }
    if (food.flag)
    {
        solidcircle(food.x ,food.y ,food.r);
    }

    EndBatchDraw();
}
int snakeDie()
{
    for (int i = 1; i < snake.Snake_length; ++i)
    {
        if (snake.location[0].x == snake.location[i].x&&
            snake.location[0].y == snake.location[i].y)
        {
            outtextxy(200, 200, "You Hit Yourself");
            MessageBox(hwnd, "Game Over!", "Attention", MB_OK);
            return 1;
        }
    }
    return 0;
}
