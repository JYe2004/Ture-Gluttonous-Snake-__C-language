/**/
#include "SNAKE.h"

int main(void)
{
    InitData();

    while(1)
    {
        Gamedraw();
        if (snakeDie())
        {
            break;
        }
        KBctrl();
        MoveSnake(); // key我就说移动不是要陪循环的吗？
        EatFood();
        Sleep(100);
    }
    return 0;
}
