#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health.
 * Example Output for names Wiz and NPC
 * Wiz health: 75 NPC health: 100\n
 * 
 * @param player1
 * @param player2
*/
void displayStats(RPG player1, RPG player2){
    cout << player1.getName() << " health: " << player1.getHealth() << " " << player2.getName() << " health: " << player2.getHealth() << "" << endl; 
}

/**
 * @brief Displays who wins based on who is alive. Use an if statement to check whether
 * player 1 is alive. If so, print that they won, else player 2 won.
 * 
 * @param player1
 * @param player2
*/
void displayEnd(RPG player1, RPG player2){
    if (player1.getHealth() > 0){
        cout << "Congraluations " << player1.getName() << ", you won!" << endl;
    }
    else {
        cout << "Congraluations " << player2.getName() << ", you won!" << endl;
    }
}

/**
 * @brief uses a while loop to check whether both players are alive.
 * If so, it calls displayStats((*player1)), (*player2))
 * Inside the while loop it:
 *  Then prints the name of player one to say that it is their turn.
 *  Then call (*player1).useSkill(player2)
 *  Then prints "----------------------------------------\n"
 * 
 * Repeat the process for player 2 acting on player 1 inside the same while loop
 *  Then prints the name of player 2 to say that it is their turn.
 *  Then call (*player2).useSkill(player1)
 * Then prints "----------------------------------------\n"
 * 
 * @param player1
 * @param player2
*/
void gameLoop(RPG * player1, RPG * player2){
    while (player1->isAlive() == true & player2->isAlive() == true){
        displayStats((*player1), (*player2));
        cout << player1->getName() << "'s turn" << endl;
        (*player1).useSkill(player2);
        printf("----------------------------------------\n");
        displayStats((*player1), (*player2));
        cout << player2->getName() << "'s turn" << endl;
        (*player2).useSkill(player1);
        printf("----------------------------------------\n");
    }
}

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage"); //Creating 1st player

    RPG p2 = RPG(); //Creating second player

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);

return 0;

}