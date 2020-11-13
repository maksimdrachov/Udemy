#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>


bool game_over;
//const int width {20};
//const int height {20};

void ClearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void Setup()
{
    game_over = false;
}

void Draw()
{
    clrscr();
    std::cout << "Playing";
    
}

void Input()
{
    
}

void Logic()
{
    
}


int main() {
    
    Setup();
    
    while (!game_over) 
    {
        Draw();
        Input();
        Logic();
        std::cout << "Message";
    }
    
    
    return 0;
}
