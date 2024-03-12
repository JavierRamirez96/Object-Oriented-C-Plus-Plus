#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1 = RPG(); //Creating 1st

    RPG p2 = RPG("Bob", 50, 10, 12, "archer");

    cout << "Current Health: " << p1.getHealth() << endl;

    p1.updateHealth(2);

    cout << "New Health: " << p1.getHealth() << endl;

    cout << "Dead or Alive?(0 = Dead, 1 = Alive): " << p1.isAlive() << endl;

    p2.updateHealth(0);

    cout << "Health: " << p2.getHealth() << endl;
    cout << "Dead or Alive?(0 = dead, 1 = alive): " << p2.isAlive() << endl;


return 0;

}
