#include "monster.h"
#include <cstdlib>

//Constructors
Monster::Monster(){
    srand(time(NULL));
    name = "Orc";
    strength = 50;
    health = 100;
    defense = 100;
    speed = 20;
}
Monster::Monster(std::string name, int strength, int health, int defense, int speed){
    srand(time(NULL));
    this->name = name;
    this->strength = strength;
    this->health = health;
    this->defense = defense;
    this->speed = speed;
}
Monster::Monster(Monster& monster){
    srand(time(NULL));
    this->name = monster.name;
    this->strength = monster.strength;
    this->health = monster.health;
    this->defense = monster.defense;
    this->speed = monster.speed;
}
Monster::~Monster(){}

void Monster::attack(Monster& monster){
    int attackSpeed = rand() % speed + 1;
    int dodgeSpeed = rand() % monster.getSpeed() + 1;
    int attackPower = rand() % strength + 1;

    std::cout << "\t" << name << " attacks " << monster.getName() << " with " << attackPower << " power.\n";

    //No damage is done
    if(dodgeSpeed > attackSpeed){ 
        std::cout << "\t" << monster.getName() << " has dodged the attack!\n";
        return;
    }

    //How much damage is done to monster 2 after applying defense
    //Calculates damage deflected and then subtracts that from the attackPower
    int damageDone = attackPower - (attackPower * (monster.getDefense()/100.0));

    //Subtract the damage done from the monster 2
    if(damageDone > 0){
        monster.setHealth(monster.getHealth() - damageDone);
        if(monster.getHealth() > 0)
            std::cout << "\t" << monster.getName() << " took " << damageDone << " and now has " << monster.getHealth() << " health.\n";
        else
            std::cout << "\t" << monster.getName() << " took " << damageDone << " and now has " << 0 << " health.\n";
    }else{
        std::cout << "\t" << monster.getName() << " blocked all of the damage.\n";
    }

    //If monster 2's health is 0 then it is dead
    if(monster.getHealth() <= 0){
        std::cout << "\t" << monster.getName() << " has been defeated." << std::endl;
    }
}
void Monster::print(){
    std::cout << "Name: " << name << "\n"
              << "Strength: " << strength << "\n"
              << "Health: " << health << "\n"
              << "Defense: " << defense << "\n"
              << "Speed: " << speed << "\n\n";
}

//Getter Methods
std::string Monster::getName(){
    return name;
}
int Monster::getStrength(){
    return strength;
}
int Monster::getHealth(){
    return health;
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
void Monster::setStrength(int strength){
    this->strength = strength;
}
void Monster::setHealth(int health){
    this->health = health;
}
void Monster::setDefense(int defense){
    this->defense = defense;
}
void Monster::setSpeed(int speed){
    this->speed = speed;
}