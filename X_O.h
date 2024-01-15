
/*
 * File:   X_O.h
 * Author: Abdulrahman Tahoun
 * Description : Header file containing class and function declarations, macros, and enumerations.
 * Created on Jan 1, 2024, 1:00 PM
 * Last Update on Jan 16, 2024, 2:00 PM
 */

#ifndef X_O_H
#define X_O_H

/*-------------- Includes ---------------*/
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/*-------------- Macro Declarations ---------------*/
#define X_O_ARRAY_LENGHT  0X10U
#define NAME_LENGHT       0X15U

#define X_SIGN   'X'
#define O_SIGN   'O'


/*-------------- Macro Functions Declarations  ---------------*/
#define gotoRowAndColumn(row, column) (cout << "\033[" << (row) << ";" << (column) << "H");

/*-------------- Data Type Declarations ---------------*/
class Player
{
private:
    char Name[NAME_LENGHT];
    short Team;
    short Color;
    short Shape;
    char Sign;

    short Player_input();
public:
    Player()
    {
    }
    Player( char NewName[], short Team = 0, short Color = 0)
    {
        strcpy(Name,NewName);
        this->Team = Team;
        this ->Color = Color;
    }
    Player(short Team)
    {
        this->Team = Team;
    }
    ~Player()
    {
        gotoRowAndColumn(3,50);
        cout << "Goodbye" << endl << endl << endl;
    }
    void Set_Name(char NewName[])
    {
        strcpy(Name,NewName);
    }
    char* Get_Name()
    {
        return Name;
    }
    void Set_Shape(short Shape)
    {
        this->Shape = Shape;
    }
    short Get_Shape()
    {
        return Shape;
    }
    void Set_Color(short Color)
    {
        this->Color = Color;
    }
    short Get_Color()
    {
        return Color;
    }

    bool operator == (Player p2);
    short Play(char *ptr);
    void Win();
};

class Game
{
private:
    short Draw_Flag = 0;
    Player Player1, Player2;
public:
    char* Board;
    Game() : Player1(1), Player2(2)
    {
        Board = new char[9];
    }
    ~Game()
    {
        delete []Board;
    }
    void Clear_Draw_Flag()
    {
        Draw_Flag = 0;
    }

    void Greathing();
    Player* Check_Winner(Player* Ptr_Player1, Player* Ptr_Player2);
    Player* Game_Page();
    void Game_Draw();
    bool Goodbye(Player* Ptr_WinPlayer);

};

typedef enum Color
{
    Black = 0,
    Blue,
    Green,
    Red = 4,
    Yellow = 6,
    Pivot = 13,
    White = 15
} Color_Code;



#endif
