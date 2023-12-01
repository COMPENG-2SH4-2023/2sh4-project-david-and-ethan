#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    
    exitFlag = false;
    loseFlag = false;

    input = '\0';
    score = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    exitFlag = false;
    loseFlag = false;

    input = '\0';
    score = 0;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{

    return exitFlag;

}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

//Input =======================

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}


int GameMechs::getBoardSizeX()
{

    return boardSizeX;

}

int GameMechs::getBoardSizeY()
{

    return boardSizeY;

}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

void GameMechs::generateFood(objPosArrayList* blockOff)
{

    srand(time(NULL));

    foodPos.symbol = 'O';
 
    int unique = 0;

    foodPos.x = (rand() % (boardSizeX - 3)) + 1;
    foodPos.y = (rand() % (boardSizeY - 2)) + 1;

    do
    {
        unique = 0;

        for(int i = 0; i < blockOff->getSize(); i++)
        {
            blockOff->getElement(player, i);
            
            if(player.x == foodPos.x && player.y == foodPos.y)
            {
                foodPos.x = (rand() % (boardSizeX - 3)) + 1;
                foodPos.y = (rand() % (boardSizeY - 2)) + 1;

            }else
            {
                unique += 1;
            }

        }

    }while(unique != blockOff->getSize());

}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}

