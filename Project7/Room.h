#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Monster.h"

using namespace std;

class Room{
    private:
        string name;
        Monster monster;
        int north;
        int south;
        int east;
        int west;
    public:
        Room();
        Room(string name, Monster monster, int north, int south, int east, int west);
        Room(const Room& room);
        ~Room();
        void Look();
        int Move(int direction);
        bool Alive();
        void Fight(Monster& monster);
        void Clean(int clean);
};

#endif //ROOM_H