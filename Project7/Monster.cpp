//---------------------------------------------------
// Purpose: Implementation of the Monster class.                      
// Author:  Josh Burbridge
//---------------------------------------------------

#include "Monster.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Monster::Monster()
{
    name = "something dead";
    strength = 0;
    health = 0;
    defense = 0;
    speed = 0;
}

Monster::Monster(const string _name, const int _strength, 
   const int _health, const int _defense, const int _speed)
{
    setName(_name);
    setStrength(_strength);
    setHealth(_health);
    setDefense(_defense);
    setSpeed(_speed);
}

Monster::Monster(const Monster& orig)
{
    name = orig.name;
    strength = orig.strength;
    health = orig.health;
    defense = orig.defense;
    speed = orig.speed;
}

Monster::~Monster()
{
}

string Monster::getName() const
{
    return name;
}

int Monster::getStrength() const
{
    return strength;
}

int Monster::getHealth() const
{
    return health;
}

int Monster::getDefense() const
{
    return defense;
}

int Monster::getSpeed() const
{
    return speed;
}

void Monster::setName(const string _name)
{
    name = _name;
}

void Monster::setStrength(const int _strength)
{
    if(_strength > MAX_STRENGTH)
        strength = MAX_STRENGTH;
    else if(_strength < 0)
        strength = 0;
    else
        strength = _strength;
}

void Monster::setHealth(const int _health)
{
    if(_health > MAX_HEALTH)
        health = MAX_HEALTH;
    else if(_health < 0)
        health = 0;
    else
        health = _health;
}

void Monster::setDefense(const int _defense)
{
    if(_defense > MAX_DEFENSE)
        defense = MAX_DEFENSE;
    else if(_defense < 0)
        defense = 0;
    else
        defense = _defense;
}

void Monster::setSpeed(const int _speed)
{
    if(_speed > MAX_SPEED)
        speed = MAX_SPEED;
    else if(_speed < 0)
        speed = 0;
    else
        speed = _speed;
}

void Monster::attack(Monster & opponent) const
{
   // Calculate power of attack
   int m1_attack = 1 + rand() % getStrength();
   cout << "\t" << getName() << " attacks " 
        << opponent.getName() << " with " << m1_attack << " power.\n";

   // Check if opponent dodged
   int m1_speed = 1 + rand() % getSpeed();
   int m2_speed = 1 + rand() % opponent.getSpeed();
   if (m2_speed > m1_speed)
        cout << "\t" << opponent.getName() << " dodged the attack!\n";

   // Opponent takes damage
   else
   {
      int m2_damage = m1_attack * (MAX_DEFENSE - opponent.getDefense()) / 100;
      opponent.setHealth(opponent.getHealth() - m2_damage);
      cout << "\t" << opponent.getName() << " took " << m2_damage 
           << " damage and now has " << opponent.getHealth() << " health.\n";
   }

   // Check if opponent died
   if (opponent.getHealth() <= 0)
      cout << "\t" << opponent.getName() << " has been defeated.\n";
}

void Monster::print() const
{
    cout << "Name: " << name 
         << "\nStrength: " << strength 
         << "\nHealth: " << health 
         << "\nDefense: " << defense 
         << "\nSpeed: " << speed << "\n\n";
}