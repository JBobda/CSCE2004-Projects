#include "Room.h"

using namespace std;

Room::Room(){
    name = "Default Room";
    north = -1;
    south = -1;
    east = -1;
    west = -1;
}
Room::Room(string name, Monster monster, int north, int south, int east, int west){
    this->name = name;
    this->monster = monster;
    this->north = north;
    this->south = south;
    this->east = east;
    this->west = west;
}
Room::Room(const Room& room){
    this->name = room.name;
    this->monster = room.monster;
    this->north = room.north;
    this->south = room.south;
    this->east = room.east;
    this->west = room.west;
}
Room::~Room(){}

void Room::Look(){
    cout << "You have entered the " << name << " Ember Tower." << endl;

    if(Alive())
        cout << "A vicious-looking " << monster.getName() << " is lurking in the shadows." << endl;
    else
        cout << "The remains of the " << monster.getName() << " are right where you left them." << endl;


    if(north != -1)
        cout << "There is a room to the North" << endl;
    if(south != -1)
        cout << "There is a room to the South" << endl;
    if(east != -1)
        cout << "There is a room to the East" << endl;
    if(west != -1)
        cout << "There is a room to the West" << endl;
}
int Room::Move(int direction){
    char A = ' ';
    cout << "Choose a direction to move: ('n', 's', 'e', 'w'): " << endl;
    cin >> A;
    while (A != 'n' && A != 's' && A!= 'e' && A != 'w'){
        cin >> A;
    }

    switch(A){
      case 'n':
          if(north != -1)
          return north;
      case 's':
          if(south != -1)
          return south;
      case 'e':
          if(east != -1)
          return east;
      case 'w':
          if('w' != -1)
          return west;
    }

    return direction;

}
bool Room::Alive(){
    if(monster.getHealth() > 0)
        return true;
    else
        return false;

}
void Room::Fight(Monster& monster){
    if(!Alive())
        cout << "No reason to attack If the " << this->monster.getName() << " is already dead";

    monster.attack(this->monster);

    if(this->monster.getHealth() > 0)
        this->monster.attack(monster);

}
void Room::Clean(int clean){
    if( north >= clean)
        north = -1;
    if( south >= clean)
        south = -1;
    if( east >= clean)
        east = -1;
    if( west >= clean)
        west = -1;

}
