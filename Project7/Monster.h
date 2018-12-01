//---------------------------------------------------
// Purpose: Header file for the Monster class. 
// Author:  Josh Burbridge
//---------------------------------------------------
#include <string>
using namespace std;

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
    //Constructors and destructor
    Monster();
    Monster(const string _name, const int _strength, 
       const int _health, const int _defense, const int _speed);
    Monster(const Monster& orig);
    ~Monster();

    //Accessors
    string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getDefense() const;
    int getSpeed() const;

    //Mutators
    void setName(const string _name);
    void setStrength(const int _strength);
    void setHealth(const int _health);
    void setDefense(const int _defense);
    void setSpeed(const int _speed);

    //Other
    void attack(Monster& opponent) const;
    void print() const;

private:
    static const int MAX_HEALTH = 100;
    static const int MAX_STRENGTH = 50;
    static const int MAX_DEFENSE = 100;
    static const int MAX_SPEED = 20;
    
    string name;
    int strength;
    int health;
    int defense;
    int speed;
};

#endif