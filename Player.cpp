#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    playerPos.setObjPos(5, 5, '*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{

//Border Wrap Code ====================================================
    if(playerPos.y > (mainGameMechsRef->getBoardSizeY() - 2))
    {
        playerPos.y = 1;
    }
    if(playerPos.y < 1)
    {
        playerPos.y = (mainGameMechsRef->getBoardSizeY() - 2);
    }

    if(playerPos.x > (mainGameMechsRef->getBoardSizeX() - 3))
    {
        playerPos.x = 1;
    }
    if(playerPos.x < 1)
    {
        playerPos.x = (mainGameMechsRef->getBoardSizeX() - 3);
    }
//====================================================
    
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = (*mainGameMechsRef).getInput();
    // PPA3 input processing logic   

    switch(input)
        {                      
            case 'w':
            case 'W':
            if(myDir != DOWN)
            {
                myDir = UP;
            }
            break;
            // Add more key processing here
            case 'd':
            case 'D':
            if(myDir != LEFT)
            {
                myDir = RIGHT;
            }
            break;
            // Add more key processing here    
            case 's':
            case 'S':
            if(myDir != UP)
            {
                myDir = DOWN;
            }
            break;

            case 'a':
            case 'A':
            if(myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

            default:
                break;
        }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    if(myDir == UP)
    {
        playerPos.y -= 1;
    }
    if(myDir == DOWN)
    {
        playerPos.y += 1;
    }
    if(myDir == RIGHT)
    {
        playerPos.x += 1;
    }
    if(myDir == LEFT)
    {
        playerPos.x-= 1;
    }

}