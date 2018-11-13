#include "monster.h"
#include <cstdlib>

//Constructors
Monster::Monster(){
    srand(time(NULL));
    name = "Orc";
    health = 100;
    strength = 50;
    defense = 100;
    speed = 20;
}
Monster::Monster(std::string name, int health, int strength, int defense, int speed){
    srand(time(NULL));
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->speed = speed;
}
Monster::Monster(Monster& monster){
    srand(time(NULL));
}
Monster::~Monster(){}

void Monster::attack(Monster& monster){
    int attackSpeed = rand() % speed + 1;
    int dodgeSpeed = rand() % monster.getSpeed() + 1;
    int attackPower = rand() % strength + 1;

    //No damage is done
    if(dodgeSpeed > attackSpeed) return;

    //How much damage is done to monster 2 after applying defense
    int damageDone = attackPower - monster.getDefense();

    //Subtract the damage done from the monster 2
    if(damageDone > 0)
        monster.setHealth(monster.getHealth() - damageDone);

    //If monster 2's health is 0 then it is dead
    if(monster.getHealth() <= 0)
        std::cout << monster.getName() << " is dead" << std::endl;
}
void Monster::print(){}

//Getter Methods
std::string Monster::getName(){
    return name;
}
int Monster::getHealth(){
    return health;
}
int Monster::getStrength(){
    return strength;
}
int Monster::getDefense(){
    return defense;
}
int Monster::getSpeed(){
    return speed;
}

//Setter Methods
void Monster::setName(std::string name){
    this->name = name;
}
void Monster::setHealth(int health){
    this->health = health;
}
void Monster::setStrength(int strength){
    this->strength = strength;
}
void Monster::setDefense(int defense){
    this->defense = defense;
}
void Monster::setSpeed(int speed){
    this->speed = speed;
}