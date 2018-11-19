#include <iostream>
#include <fstream>
#include "monster.h"

int main(){
    //Initializing ifstream object, opening monsters.txt and creating a monster array as specified
    std::ifstream reader;
    reader.open("monsters.txt");
    int count = 0;
    reader >> count;
    Monster monsters[count];

    std::string name = "";
    int strength = 0;
    int health = 0;
    int defense = 0;
    int speed = 0;

    //Loading up and printing all of the monsters in the text file
    for(int i = 0; i < count; i++){
        reader >> name;
        reader >> strength;
        reader >> health;
        reader >> defense;
        reader >> speed;
        Monster monster(name, strength, health, defense, speed);
        monsters[i] = monster;
        monsters[i].print();
    }

    //Asking the user to select the monsters to battle
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