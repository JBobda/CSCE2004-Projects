#include "Room.h"

using namespace std;

Room::Room(){}
Room::Room(string name, Monster monster, int north, int south, int east, int west){}
Room::Room(const Room& room){}
Room::~Room(){}
void Room::Look(){}
int Room::Move(int direction){}
bool Room::Alive(){}
void Room::Fight(Monster& monster){}
void Room::Clean(int clean){}