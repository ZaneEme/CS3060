#include <iostream>
#include <string>

using namespace std;

struct Character {
    int Hitpoints;
    char Name[20];
    int Damage;
};

void setCharacter(Character &c);
int DisplayDamage(Character c);
void DealDamage(Character &c, int Damage);

int main() {
    Character c;
    setCharacter(c);
    int damage = DisplayDamage(c);
    DealDamage(c, damage);
    return 0;
}

void setCharacter(Character &c) {
    // Sets the character's name, hitpoints, and damage
    cout << "Enter the name of your character: ";
    cin >> c.Name;
    cout << "Enter the amount of health your character has: ";
    cin >> c.Hitpoints;
    cout << "Enter max damage your character deals: ";
    cin >> c.Damage;
}


int DisplayDamage(Character c) {
    // Returns a value between 1 and the max damage of the character
    // Will not process if the character is not set
    if (!c.Hitpoints || !c.Name || !c.Damage) {
        cout << "Character not set!" << endl;
        return 0;
    }

    int damage = rand() % c.Damage + 1;
    cout << c.Name << " takes " << damage << " damage!" << endl;
    return damage;
}

void DealDamage(Character &c, int Damage) {
    // Deals damage to the character
    // Will not process if the character is not set
    // Will kill the character if the damage is greater than their hitpoints
    if (!c.Hitpoints || !c.Name || !c.Damage) {
        cout << "Character not set!" << endl;
        return;
    }

    if (Damage > c.Hitpoints) {
        cout << c.Name << " has died!" << endl;
    } else {
        c.Hitpoints -= Damage;
        cout << c.Name << " has " << c.Hitpoints << " health remaining." << endl;
    }
}
