#include "Room.h"

using namespace std;

//Default Constructor
Room::Room(){
    name = "Default Room";
    north = -1;
    south = -1;
    east = -1;
    west = -1;
}

//Primary Constructor
Room::Room(string name, Monster monster, int north, int south, int east, int west){
    this->name = name;
    this->monster = monster;
    this->north = north;
    this->south = south;
    this->east = east;
    this->west = west;
}

//Copy Constructor
Room::Room(const Room& room){
    this->name = room.name;
    this->monster = room.monster;
    this->north = room.north;
    this->south = room.south;
    this->east = room.east;
    this->west = room.west;
}

//Destructor
Room::~Room(){}

//Look method that prints the room name and the monster's alive status
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

//Move method that moves the player into a room chosen by the input, given that it is valid
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

//Checks if the monster inside the room
bool Room::Alive(){
    if(monster.getHealth() > 0)
        return true;
    else
        return false;

}

//Fight method, the player attacks the monster, then the monster, if it is still alive, attacks back
void Room::Fight(Monster& monster){
    if(!Alive())
        cout << "No reason to attack If the " << this->monster.getName() << " is already dead";

    monster.attack(this->monster);

    if(this->monster.getHealth() > 0)
        this->monster.attack(monster);

}

//Cleans the program of any rooms that should not exist
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
