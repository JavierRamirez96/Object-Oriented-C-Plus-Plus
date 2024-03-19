#ifndef RPG_H
#define RPG_H
#include <iostream>

using namespace std;

const int SKILL_SIZE = 2;

class RPG{
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        void setSkills();
        void printAction(string, RPG);
        void updateHealth(int);
        void attack(RPG *);
        void useSkill(RPG *);
       // Accessor funcions return private functions
        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;
        string getType () const;


    // private variables are initialized
    private:
        string name;
        int health;
        int strength;
        int defense;
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE];
};

#endif