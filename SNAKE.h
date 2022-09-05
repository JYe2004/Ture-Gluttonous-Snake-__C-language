//
// Created by 33559 on 2022/9/5.
//



#ifndef SNAKEIT_SSSNAKE_H
#define SNAKEIT_SSSNAKE_H
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#define SNAKE_ALL 500


enum {
    UP,DOWN,LEFT,RIGHT
};
typedef struct{
    int Snake_length;
    int Snake_way;
    int Snake_speed;
    POINT location[SNAKE_ALL];
}Snake;

typedef struct {
    int x;
    int y;
    int r;
    int Food_color;
    int Food_grade;
    bool flag;
}Food;
void InitData();
void KBctrl();
void MoveSnake();
void EatFood();
void Gamedraw();
int snakeDie();
#endif //SNAKEIT_SSSNAKE_H

