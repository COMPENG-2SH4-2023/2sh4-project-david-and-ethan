#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(5, 5, '*');


    //playerPos.setObjPos(5, 5, '*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    // For debuggin, insert another 4 segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);


}


Player::~Player()
{
    // delete any heap members here

    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{

//Border Wrap Code ====================================================
    /*if(playerPos.y > (mainGameMechsRef->getBoardSizeY() - 2))
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
    }*/
//====================================================
    
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
    return playerPosList;
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

    //objPos newHead;

    objPos currentHead;    //holding the pos info of the current head
    playerPosList->getHeadElement(currentHead);

    if(myDir == UP)
    {
        currentHead.y -= 1;

        if(currentHead.y < 1)
        {
            currentHead.y = (mainGameMechsRef->getBoardSizeY() - 2);
        }


    }
    if(myDir == DOWN)
    {
        currentHead.y += 1;

        if(currentHead.y > (mainGameMechsRef->getBoardSizeY() - 2))
        {
            currentHead.y = 1;
        }
    }
    if(myDir == RIGHT)
    {
        currentHead.x += 1;

        if(currentHead.x > (mainGameMechsRef->getBoardSizeX() - 3))
        {
            currentHead.x = 1;
        }
    }
    if(myDir == LEFT)
    {
        currentHead.x-= 1;

        if(currentHead.x < 1)
        {
            currentHead.x = (mainGameMechsRef->getBoardSizeX() - 3);
        }

    }

    


   
    // new current hed should be inserted t othe head of the llist
   playerPosList->insertHead(currentHead);

    // then, remove tail
    playerPosList->removeTail();

}