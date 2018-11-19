#include <iostream>
#include <fstream>
#include "monster.h"

int main(){
    std::ifstream reader;
    reader.open("monsters.txt");
    int count = 0;
    reader >> count;
    Monster monsters[count];

    std::string name = "";
    int health = 0;
    int strength = 0;
    int defense = 0;
    int speed = 0;

    for(int i = 0; i < count; i++){
        reader >> name;
        reader >> health;
        reader >> strength;
        reader >> defense;
        reader >> speed;
        Monster monster(name, health, strength, defense, speed);
        monsters[i] = monster;
        monsters[i].print();
    }

    int firstMonster = 0;
    int secondMonster = 0;
    std::cout << "Choose first monster for battle [0.." << (count-1) << "]:"; 
    std::cin >> firstMonster;
    std::cout << "Choose second monster for battle [0.." << (count-1) << "]:";
    std::cin >> secondMonster;

    //Battle simulation
    int roundCounter = 1;
    while(monsters[firstMonster].getHealth() > 0 && monsters[secondMonster].getHealth() > 0){
        std::cout << "\nRound " << roundCounter << "\n";
        std::cout << "--------\n";

        monsters[firstMonster].attack(monsters[secondMonster]);
        
        if(monsters[secondMonster].getHealth() <= 0) break;

        std::cout << "\nRound " << roundCounter+1 << "\n";
        std::cout << "--------\n";

        monsters[secondMonster].attack(monsters[firstMonster]);
        
        if(monsters[firstMonster].getHealth() <= 0) break;

        roundCounter+=2;
    }
    
    return 0;
}