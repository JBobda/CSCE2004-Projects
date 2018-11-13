#include <iostream>
#include "monster.h"

int main(){
    Monster monster("Troll", 50, 50, 50, 10);
    std::cout << monster.getName() << std::endl;
    return 0;
}