#include "X_O.h"

extern Game MyGame;

int main()
{
    Player* Win_Player;
    bool Choice_Flag = 1;

    MyGame.Greathing();
    while(Choice_Flag)
    {
        Choice_Flag = 0;
        Win_Player = NULL;
        MyGame.Clear_Draw_Flag();
        Win_Player = MyGame.Game_Page();
        Choice_Flag = MyGame.Goodbye(Win_Player);
    }

    return 0;
}
