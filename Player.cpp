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
     returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = (*mainGameMechsRef).getInput();
    // PPA3 input processing logic   
    switch((*mainGameMechsRef).getInput())
    {
        case STOP:
            if(input == 'W' || input == 'w')
            {
                myDir = UP;
                
                break;
            }
            if(input == 'A' || input == 'a')
            {
                myDir = LEFT;
               
                break;
            }                
            if(input == 'S' || input == 's')
            {
                myDir = DOWN;
                
                break;
            }               
            if(input == 'D' || input == 'd')
            {
               myDir = RIGHT;
              
                break;
            }
            break;

        // Add more key processing here
        case LEFT:
            if(input == 'W' || input == 'w')
            {
                myDir = UP;
                
                break;
            }
            if(input == 'S' || input == 's')
            {
                myDir = DOWN;
                
                break;
            }            
            break;

        // Add more key processing here 
        case UP:
            if(input == 'A' || input == 'a')
            {
               myDir = LEFT;
                
                break;
            }
            if(input == 'D' || input == 'd')
            {
                myDir = RIGHT;
                
                break;
            }         
            break;
        
        case RIGHT:
            if(input == 'W' || input == 'w')
            {
                myDir = UP;
              
                break;
            }
            if(input == 'S' || input == 's')
            {
                myDir = DOWN;
               
                break;
            }                
            break;
        
        case DOWN:
            if(input == 'A' || input == 'a')
            {
                myDir = LEFT;
                
                break;
            }
            if(input == 'D' || input == 'd')
            {
                myDir = RIGHT;
                
                break;
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

