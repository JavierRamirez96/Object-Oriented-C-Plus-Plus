#include "RPG.h"
#include <iostream>

using namespace std;

RPG::RPG(){
//Initializes private variables
  name = "NPC";
  health = 100;
  strength = 10;
  defense = 10;
  type = "warrior";
  skills[0] = "slash";
  skills[1] = "parry";
}

/// @brief defines overloaded function
/// @param name 
/// @param health 
/// @param strength 
/// @param defense 
/// @param type 
RPG::RPG(string name, int health, int strength, int defense, string type){
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    // Calls set skills to set skills based on type
    setSkills();
}

/**
 * @brief sets the skills based on the RPG's role
 * 
*/
void RPG::setSkills(){
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    }
    else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    }
    else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    }
    else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(string skill , RPG opponent)
{
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

/// @brief updates health into new_health
/// @param new_health
void RPG::updateHealth(int new_health)
{ 
    health = new_health;
}

/**
 * @brief returns whether health is greater than 0
 *
 * @return true
 * @return false
 */
bool RPG::isAlive() const
{
    return health > 0;
}

/**
 * @brief accessor functions returns private variables
*/
string RPG::getName() const
{
    return name;
}
int RPG::getHealth() const
{
    return health;
}

int RPG::getStrength() const
{
    return strength;
}

int RPG::getDefense() const
{
    return defense;
}

string RPG::getType() const
{
    return type;
}

/**
 * @brief attack decreases the opponent's health by (strength - opponent's defense)
 * In other words, the opponent's defense should soften the blow from the attack
 * 
 * For example, if the opponent's health is 100, opponent's defense is 5, and player's
 * strength is 20, then after the attack, opponent's health should be
 * 85 (i.e. 100 - (20-5)).
 * 
 * @param opponent
*/
void RPG::attack(RPG * opponent){
    int opp_health = (*opponent).getHealth();

    int opp_def = (*opponent).getDefense();

    int new_health = 0;

    if(strength - opp_def > 0){
        int new_health = opp_health - (strength - opp_def);
        (*opponent).updateHealth(new_health);
    }
    else {
        int new_health = opp_health - 0;
        (*opponent).updateHealth(new_health);
    }
}

/**
 * @brief Prompts the user to choose a skill and calls printAction() and attack()
 * 
 * @param opponent
*/
void RPG::useSkill(RPG * opponent){
    for(int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    int chosen_skill_index;
    printf("Choose a skill to use: Enter 0 or 1\n");

    cin >> chosen_skill_index;

    string chosen_skill = skills[chosen_skill_index];

    printAction(chosen_skill, (*opponent));

    attack(opponent);

}