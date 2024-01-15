/*
 * File:   Functions.cpp
 * Author: Abdulrahman Tahoun
 * Description : Source file containing Classes Methods Implementation  and the implementation of helper or static functions.
 *  Created on Jan 1, 2024, 1:00 PM
  * Last Update on Jan 16, 2024, 2:00 PM
 */

/*-------------- Includes ---------------*/
#include "X_O.h"

/*-------------- Helper Functions Declarations ---------------*/
static void Star_Shape(Color_Code Color_t);
static void Welcom_Massege();
static void X_O_board();
static void ClearConsoleToColors(int ForgC, int BackC);
static void SetColor(int ForgC);
static void Board_Init();

/*-------------- Global Variable Definitions  ---------------*/
Game MyGame;

/*-------------- APIs Definitions ---------------*/
void Game::Greathing()
{
    char Name[NAME_LENGHT];
    short Shape;
    short Color;
    Welcom_Massege();
    cout << "\t\tPlayer 1\n--------------------------------\n\t\tEnter your name : ";
    cin >>  Name;
    Player1.Set_Name(Name);
    fflush(stdin);
    system("cls");

    cout << "\t\tPlayer 1\n" ;
    cout <<"--------------------------------\n\t\tSelect your Team\n\t\t1- X Team\n\t\t2- O Team\n--------------------------------\n";
    do
    {
        cout <<"\t\t>Please Enter Number 1 or 2 : ";
        while(scanf("%hu", &(Shape)) != 1)
        {
            cout <<"\t\t>Invalid Input!!, Please Enter a Number : ";
            while(getchar() != '\n');
        }
    }
    while((Shape != 1) && (Shape != 2));
    Player1.Set_Shape(Shape);
    fflush(stdin);
    system("cls");

    cout <<"\t\tPlayer 1\n";
    cout <<"--------------------------------\n\t\tSelect your color\n\t\t1-Red\n\t\t2-Green\n\t\t3-Yellow\n\t\t4-Blue\n--------------------------------\n";
    do
    {
        cout <<"\t\t>Please Enter Number from 1 to 4 : ";
        while(scanf("%hu", &(Color)) != 1)
        {
            cout <<"\t\t>Invalid Input!!, Please Enter a Number : ";
            while(getchar() != '\n');
        }
    }
    while((Color > 4) || (Color < 1));
    Player1.Set_Color(Color);
    fflush(stdin);
    system("CLS");

    cout <<"\t\tPlayer 2\n--------------------------------\n";
    cout <<"\t\tEnter your name : ";
    cin >> Name;
    Player2.Set_Name(Name);
    while(Player2 == Player1)
    {
        cout <<"\t\tEnter different name : ";
        cin >> Name;
        Player2.Set_Name(Name);
    }

    fflush(stdin);
    system("cls");

    if(1 == Player1.Get_Shape())
    {
        Player2.Set_Shape(2);
    }
    else
    {
        Player2.Set_Shape(1);
    }

    cout <<"\t\tPlayer 2\n";
    cout <<"--------------------------------\n\t\tSelect your color\n\t\t1-Red\n\t\t2-Green\n\t\t3-Yellow\n\t\t4-Blue\n--------------------------------\n";
    do
    {
        cout <<"\t\t>Please Enter Number from 1 to 4 : ";
        while(scanf("%hu", &(Color)) != 1)
        {
            cout <<"\t\t>Invalid Input!!, Please Enter a Number : ";
            while(getchar() != '\n');
        }
    }
    while((Color > 4) || (Color < 1) || (Color == Player1.Get_Color()));
    {

    }
    Player2.Set_Color(Color);
    fflush(stdin);

    switch(Player1.Get_Color())
    {
    case 1 :
        Player1.Set_Color(Red);
        break;
    case 2 :
        Player1.Set_Color(Green);
        break;
    case 3 :
        Player1.Set_Color(Yellow);
        break;
    case 4 :
        Player1.Set_Color(Blue);
        break;
    default:
        break;
    }

    switch(Player2.Get_Color())
    {
    case 1 :
        Player2.Set_Color(Red);
        break;
    case 2 :
        Player2.Set_Color(Green);
        break;
    case 3 :
        Player2.Set_Color(Yellow);
        break;
    case 4 :
        Player2.Set_Color(Blue);
        break;
    default:
        break;
    }

    system("CLS");
}

bool Player::operator == (Player p2)
{
    if(strcmp(Name, p2.Name))
        return 0;
    else
        return 1;
}

Player* Game::Game_Page()
{
    Player* WinPlayer = NULL;
    int Counter = 0;
    Board_Init();
    SetColor(Pivot);
    ClearConsoleToColors(0,White);
    gotoRowAndColumn(2,40);
    cout << "Player 1 [" << Player1.Get_Name() << "] : > ";
    gotoRowAndColumn(3,40);
    cout << "Player 2 [" << Player2.Get_Name()  << "] : > ";
    X_O_board();

    while(WinPlayer == NULL && Draw_Flag == 0)
    {
        Counter = Player1.Play(MyGame.Board);
        WinPlayer = Check_Winner(&Player1, &Player2);
        if(WinPlayer != NULL || Draw_Flag == 1)
            break;

        Counter++;
        Counter = Player2.Play(MyGame.Board);
        WinPlayer = Check_Winner(&Player1, &Player2);
        if(WinPlayer != NULL || Draw_Flag == 1)
            break;

        Counter++;
    }
    return WinPlayer;
}

short Player::Play(char *ptr)
{
    short Location = 0, Flag = 0;

    if(this->Shape == 1)
    {
        Sign = X_SIGN;
    }
    else
    {
        Sign = O_SIGN;
    }

    SetColor(Color);

    while(Flag == 0)
    {
        Location = Player_input();
        switch(Location)
        {
        case 1 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                gotoRowAndColumn(13,47);
                SetColor(Color);
                cout << Sign;
                *(ptr+Location-1) = Sign;
                Flag = 1;
            }
            break;
        case 2 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(13,53);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 3 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(13,59);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 4 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(15,47);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 5 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(15,53);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 6 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(15,59);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 7 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(17,47);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 8 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(17,53);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        case 9 :
            if(*(ptr+Location-1) == X_SIGN || *(ptr+Location-1) == O_SIGN)
            {
                Flag = 0;
            }
            else
            {
                *(ptr+Location-1) = Sign;
                gotoRowAndColumn(17,59);
                SetColor(Color);
                cout << Sign;
                Flag = 1;
            }
            break;
        default:
            Flag = 0;
            break;
        }
    }

    return Location;
}

short Player::Player_input()
{
    short Location = 0, Flag = 0, Num;
    if(Team == 1)
    {
        gotoRowAndColumn(2,57+strlen(Name));
    }
    else
    {
        gotoRowAndColumn(3,57+strlen(Name));
    }

    while((Location=getch()) != 13 )
    {
        if(Location >= '1' && Location <= '9')
        {
            Flag++;
            if(Flag <= 1)
            {
                Num = Location-'0';
                cout << Num;
            }
            else
                cout << '\a';
        }
        else
        {
            if('\b' == Location)
            {
                if(Flag != 0)
                {
                    cout << '\b' << " " << '\b';
                    Flag = 0;
                }

            }
            else
                cout << '\a';
        }
    }
    cout << '\b' << " " << '\b';
    return Num;
}

Player * Game::Check_Winner(Player* Ptr_Player1, Player* Ptr_Player2)
{
    static short Counter = 1;
    short Num = 0;

    if(Counter > 4 && Counter <= 9)
    {
        Counter++;
        while(Num < 7)
        {
            if(*(MyGame.Board+Num)== *(MyGame.Board+1+Num) && *(MyGame.Board+Num) == *(MyGame.Board+2+Num))
            {
                if(*(MyGame.Board+Num) == 'X')
                {
                    Counter = 1;
                    return Ptr_Player1;
                }
                else if(*(MyGame.Board+Num) == 'O')
                {
                    Counter = 1;
                    return Ptr_Player2;
                }
                else
                {
                    Num += 3;
                }
            }
            else
            {
                Num += 3;
            }
        }
        Num = 0;
        while(Num < 3)
        {
            if(*(MyGame.Board+Num)== *(MyGame.Board+3+Num) && *(MyGame.Board+Num) == *(MyGame.Board+6+Num))
            {
                if(*(MyGame.Board+Num) == 'X')
                {
                    Counter = 1;
                    return Ptr_Player1;
                }
                else if(*(MyGame.Board+Num) == 'O')
                {
                    Counter = 1;
                    return Ptr_Player2;
                }
                else
                {
                    Num += 3;
                }
            }
            else
            {
                Num += 1;
            }
        }

        if(*(MyGame.Board+0)== *(MyGame.Board+4) && *(MyGame.Board+0) == *(MyGame.Board+8))
        {
            if(*(MyGame.Board+0) == 'X')
            {
                Counter = 1;
                return Ptr_Player1;
            }
            else if(*(MyGame.Board+0) == 'O')
            {
                Counter = 1;
                return Ptr_Player2;
            }
            else {}
        }
        else if(*(MyGame.Board+2)== *(MyGame.Board+4) && *(MyGame.Board+2) == *(MyGame.Board+6))
        {
            if(*(MyGame.Board+2) == 'X')
            {
                Counter = 1;
                return Ptr_Player1;
            }
            else if(*(MyGame.Board+2) == 'O')
            {
                Counter = 1;
                return Ptr_Player2;
            }
            else {}
        }

    }
    else
    {
        Counter++;
    }

    if(Counter > 9)
    {
        Counter = 1;
        Draw_Flag = 1 ;
    }

    return NULL;
}

void Player::Win()
{
    system("cls");
    ClearConsoleToColors(0,White);
    Star_Shape(Pivot);
    gotoRowAndColumn(6,40);
    SetColor(Green);
    gotoRowAndColumn(10,40);
    cout << "\t\t\t Congratulations    \t\t";
    gotoRowAndColumn(12,40);
    cout <<"\t\t\t   -----" <<this->Name << "-----   \t\t";
    gotoRowAndColumn(14,40);
    cout << "\t\t\tyou are the winner \t\t\n" ;
    SetColor(Pivot);

    gotoRowAndColumn(22,1);
    cout << "Press any key to continue...........";
    getch();
    system("cls");
}

void Game::Game_Draw()
{
    system("cls");
    ClearConsoleToColors(0,White);
    Star_Shape(Pivot);
    SetColor(Black);

    gotoRowAndColumn(11,40);
    cout << "\t\t" << "-----------Game Draw-----------" << "\t\t";

    gotoRowAndColumn(22,1);
    cout << "Press any key to continue...........";
    getch();
    system("cls");
}

bool Game::Goodbye(Player* Ptr_WinPlayer)
{
    short choice = 0;
    if(Ptr_WinPlayer == NULL && Draw_Flag == 1)
    {
        MyGame.Game_Draw();
    }
    else
    {
        Ptr_WinPlayer->Win();
    }
    cout <<endl<< "1-Play again." << endl << endl << "2-Exit program." << endl<<endl<<"------------------------------"<<endl<< endl;
    do
    {
        cout << ">Enter your choice : ";
        while((scanf("%hu", &choice)) != 1)
        {
            cout <<">Invalid Input!!, Please Enter a Number : ";
            while(getchar() != '\n');
        }
    }
    while((choice != 1) && (choice != 2));
    system("cls");
    if(choice == 1)
    {
        return 1;
    }
    else
    {
        ClearConsoleToColors(0, Black);
        SetColor(White);
        return 0;
    }
}

/*-------------- Helper or Static Functions Definitions ---------------*/
static void Welcom_Massege()
{
    system("cls");
    ClearConsoleToColors(0,Black);
    Star_Shape(Pivot);
    SetColor(Yellow);
    gotoRowAndColumn(6,40);
    gotoRowAndColumn(10,40);
    cout << "\t\t\t-----Welcome-----\t\t";
    gotoRowAndColumn(11,40);
    cout << endl;
    gotoRowAndColumn(12,40);
    cout << "\t\t       " << "This is an X_O Game";

    gotoRowAndColumn(22,1);
    cout << "Press any key to continue...........";
    getch();
    system("cls");

}

static void Board_Init()
{
    for(short Counter1 = 0; Counter1 < 9; Counter1++)
    {
        *(MyGame.Board + Counter1) = ' ';
    }
}

static void X_O_board()
{
    SetColor(Black);
    gotoRowAndColumn(8,40);
    cout << "---------------------------";
    gotoRowAndColumn(13,45);
    cout << "     |     |" << endl;
    gotoRowAndColumn(14,45);
    cout << "=====*=====*=====" << endl;
    gotoRowAndColumn(15,45);
    cout << "     |     |"<< endl;
    gotoRowAndColumn(16,45);
    cout << "=====*=====*=====" << endl;
    gotoRowAndColumn(17,45);
    cout << "     |     |"<< endl;

}

static void Star_Shape(Color_Code Color_t)
{
    SetColor(Color_t);
    gotoRowAndColumn(6,40);
    cout << "**************************************************";
    gotoRowAndColumn(7,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(8,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(9,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(10,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(11,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(12,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(13,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(14,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(15,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(16,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(17,40);
    cout << "*\t\t\t\t\t\t*";
    gotoRowAndColumn(18,40);
    cout << "**************************************************";
}
static void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
static void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}
