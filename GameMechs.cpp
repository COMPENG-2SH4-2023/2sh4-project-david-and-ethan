#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    
    exitFlag = false;
    loseFlag = false;

    input = NULL;
    score = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    exitFlag = false;
    loseFlag = false;

    input = NULL;
    score = 0;
}

// do you need a destructor?

GameMechs::~GameMechs() 
{

    
	
}

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
    input = NULL;
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

