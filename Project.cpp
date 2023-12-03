#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

//Objects ===================

GameMechs* GameMechRef;
objPos* myPos;
Player* playerObject;
int **gridScreen;

objPos* foodPos;

//===========================

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
bool loseFlag;

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
    playerObject = new Player(GameMechRef);
    myPos = new objPos();
    foodPos = new objPos();
    
//Initialize Gridscreen object array to the heap ====================

    gridScreen = new int*[GameMechRef->getBoardSizeX() + 2]; //Plus 2 to account for \n and null character(Actually not sure if we need to account for null character)

	for(int i = 0; i < GameMechRef->getBoardSizeX() + 2; i++)
	{
		gridScreen[i] = new int[GameMechRef->getBoardSizeY()];
	}
//===================================================================


    //makeshift objPos tempPos(1, 1, 'O');

    objPosArrayList* playerBody = playerObject->getPlayerPos();

    GameMechRef->generateFood(playerBody);

    exitFlag = false;
}

void GetInput(void)
{
    char input = GameMechRef->getInput();
}

void RunLogic(void)
{
    bool drawn;

    objPosArrayList* playerBody = playerObject->getPlayerPos();
    objPos tempBody;

//Move Player =====

    if(loseFlag == false)
    {
        playerObject->updatePlayerDir();
        playerObject->movePlayer();
    }

//================

    //Just resets myPos, not playerpos. So when you copy playerpos back into mypos it just pops back out?

    char Playersymbol = myPos->symbol;

    GameMechRef->getFoodPos(*foodPos);


//Assign Members to Grid ============================================

    for(int y = 0; y < GameMechRef->getBoardSizeY(); y++)
    {
        for(int x = 0; x < GameMechRef->getBoardSizeX(); x++)
        {

            drawn = false;

            //iterates through every element in list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == x && tempBody.y == y)
                {
                    gridScreen[x][y] = tempBody.symbol;
                    drawn = true;
                    break;
                    //MacUILib_printf("%c", tempBody.symbol);
                }
            }
            /*if(x == myPos->x && y == myPos->y)
            {

                gridScreen[myPos->x][myPos->y] = Playersymbol;
    
            }*/

            if(drawn) continue;

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

            if(x == (*foodPos).x &&  y == (*foodPos).y)
            {
                gridScreen[x][y] = (*foodPos).symbol;

            }
        }
    }
//======================================================

exitFlag = GameMechRef->getExitFlagStatus();
loseFlag = playerObject->checkSelfCollision();


}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 

    if(loseFlag == false)
    {

    int x = 0;
    int y = 0;

    for(x = 0; y < GameMechRef->getBoardSizeY(); y++)
    {
        for(x = 0; x < GameMechRef->getBoardSizeX(); x++)
        {
            MacUILib_printf("%c", gridScreen[x][y]);
        }       
    }

    /*MacUILib_printf("Object:\n");
    for(int l = 0; l < playerBody->getSize(); l++)
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);
    }*/

    MacUILib_printf("\nSCORE:%d\n", GameMechRef->getScore());

    switch(GameMechRef->getInput())
    {
        case '\0':
            MacUILib_printf("Snake Direction: STOP\n");
            break;

        case 'w':
            MacUILib_printf("Snake Direction: UP\n");
            break;

        case 's':
            MacUILib_printf("Snake Direction: DOWN\n");
            break;

        case 'a':
            MacUILib_printf("Snake Direction: LEFT\n");
            break;

        case 'd':
            MacUILib_printf("Snake Direction: RIGHT\n");
            break;
    }

    }else
    {
        MacUILib_printf("YOU STINK: YOUR SCORE:%d\n", GameMechRef->getScore());
    }

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

    delete GameMechRef;
    delete playerObject;
    delete myPos;
    delete foodPos;

    delete[] gridScreen;
    gridScreen = NULL;
}
