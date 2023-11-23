#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"

//Objects ===================

GameMechs* GameMechRef;
Player* playerObject;
objPos* myPos;
int **gridScreen;

//===========================

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    GameMechRef = new GameMechs(30,15);

//Initialize Gridscreen object array to the heap ====================

    gridScreen = new int*[GameMechRef->getBoardSizeX() + 2]; //Plus 2 to account for \n and null character(Actually not sure if we need to account for null character)

	for(int i = 0; i < GameMechRef->getBoardSizeX() + 2; i++)
	{
		gridScreen[i] = new int[GameMechRef->getBoardSizeY()];
	}
//===================================================================

    exitFlag = false;
}

void GetInput(void)
{
    char input = GameMechRef->getInput();
}

void RunLogic(void)
{

//Assign Members to Grid ============================================

    for(int y = 0; y < GameMechRef->getBoardSizeY(); y++)
    {
        for(int x = 0; x < GameMechRef->getBoardSizeX(); x++)
        {

            if(x == 0 || x == GameMechRef->getBoardSizeX() - 2)
            {
                gridScreen[x][y] = '#';

            }else if(y == 0 || y == GameMechRef->getBoardSizeY() -1)
            {
                gridScreen[x][y] = '#';
            }
            else   
            {
                gridScreen[x][y] = ' ';
            }

            if (x == GameMechRef->getBoardSizeX() -1)
            {
                gridScreen[x][y] = '\n';   
            }
        }
    }
//======================================================

}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 

    int x = 0;
    int y = 0;

    for(x = 0; y < GameMechRef->getBoardSizeY(); y++)
    {
        for(x = 0; x < GameMechRef->getBoardSizeX(); x++)
        {
            MacUILib_printf("%c", gridScreen[x][y]);
        }       
    }

    //MacUILib_printf("Object: <%d, %d> with %c\n", myPos.x, myPos.y, myPos.symbol);
    //Haven't setup myPos so uh this breaks
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    MacUILib_uninit();

    GameMechRef->clearInput();

    //Gotta put all the delete's here still


}
