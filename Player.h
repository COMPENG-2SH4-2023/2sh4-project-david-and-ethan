#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();


        void movePlayer();
        //need more ations in here
        // - after inserting the head but before removing the tail
        // - check if new head collides with food
        // - if yes, increment score in Game Mech, generate new food 
        //   and do not remove tail
        // - otherwise, remove tail and move on


        //lastly, add self collision check
        // - if self collided
        //  set loseFlag and exitFlas both to true (though Game MECH)
        //  this will break the program loop and end the game
        // if end, print gend game statement
        

    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        
};

#endif