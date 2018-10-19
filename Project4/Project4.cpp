#include <cstdlib>
#include <iostream>
using namespace std;

// Function prototypes
int FindWater(int max_water);
void GainFood(int max_food, int & food_gained);
char GetDirection();
void addFood(int max_food, int& food);

//Functions for locations
void Exit(int &water, int &food);
void Mountain1(int &water, int &food);
void Mountain2(int &water, int &food);
void Mountain3(int &water, int &food);
void Mountain4(int &water, int &food);
void Mountain5(int &water, int &food);
void Mountain6(int &water, int &food);
void Mountain7(int &water, int &food);
void Mountain8(int &water, int &food);

//------------------------------------------------------------
// Purpose: To calculate how much water user has.
// Input:   Maximum water (int -100..100).     
// Output:  Actual water (int -100..100).
//------------------------------------------------------------
int FindWater(int max_water){
   // Range checking of parameters
   if (max_water < -100) max_water = -100;
   if (max_water >  100) max_water =  100;

   cout << "Do you want to pick this bottled water up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle yes answer
   int water = 0;
   if (answer == "yes"){
      float fraction = (1.0 + random() % 100) / 100.0;
      water = fraction * max_water;
      if (water > 0)
         cout << "You found " << water << " L water " << endl;
      else
         cout << "You fell down and lost " << water << " L water" << endl;
   } 

   // Handle no answer
   else if (answer == "no"){ 
      if (max_water > 0)
         cout << "Too bad, you need around 4-5 liters of water at altitude to feel great" << endl;
      else      
         cout << "Good thing you didn't get it, it is empty" << endl;
   }

   // Handle wrong answer
   else { 
      cout << "A simple 'yes' or 'no' would be nice..." << endl;
      cout << "Better luck next time you see an item" << endl;
   }
   return water;
}


//------------------------------------------------------------
// Purpose: To calculate how much food user has.
// Input:   Maximum food (int 1..100).
// Output:  Actual food gained (int 1..100).
//------------------------------------------------------------
void GainFood(int max_food, int & food_gained){
   // Range checking of parameters
   if (max_food < 1)  max_food = 1;
   if (max_food > 100) max_food = 100;

   cout << "Do you want to pick this airdropping package up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle help answer
   if (answer == "yes"){
      food_gained = 1 + random() % max_food;
      cout << "Congratulations, you gained " << food_gained << " food points" << endl;
   } 

   // Handle other answers
   else{ 
      food_gained = -(1 + random() % max_food);
      if (random() % 2 == 0)
         cout << "Illusion! Thats not a real package" << endl;
      else
         cout << "You lost " << food_gained << " food points" << endl;
   }
}

//------------------------------------------------------------
// Purpose: Make a clean way to call the GainFood Function
// Input:   Maximum food (int 1..100).
// Output:  N/A
//------------------------------------------------------------
void addFood(int max_food, int& food){
      int foodGained;
      GainFood(max_food, foodGained);
      food += foodGained;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection(){
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W')){
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }
   return direction;
}

//------------------------------------------------------------
// Purpose: The ending Mountain for the game (Anna Purna)
// Input:   The water and food variables 
// Output:  None
//------------------------------------------------------------
void Exit(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have already finished the summits challenge\n";
   cout << "I hope you enjoyed this trip\n";
   cout << "You got \n";
   cout << "\nWater: " << water << " Food: " << food << endl;
   
   // Give prizes
   if (water <= 0) {
      cout << "\nYou feel thirsty and give up climbing other highest point in the world\n";
   }
   else if (food <= 0){
      cout << "\nYou feel hungry and give up climbing other highest point in the world\n";
   }
   else if ((water > 100) && (food > 100)){
      cout << "\nThe eight summits challenge is the ultimate lifetime achievement for those looking for adventure\n";

   }
   else if ((water > 10) && (food > 10)){
      cout << "\nGreat job.  You get a ticket to the Vinson Massif Mountain(Located in Antarctica)\n";
   }
   else {
      cout << "\nYou got juicy and tasty steak\n";
   }

   // Leave program
   exit(0);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Kosciuszko Mountain(Highest point in Australia)
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain1(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Kosciuszko Mountain(Highest point in Australia) \n";
   cout << "\nYou found it is harder to spell Mt kosciuszko than it is to climb it) \n";

   water += FindWater(5);
   addFood(20, food);
   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'W'){
       cout << "\nThat's not an option from this Mountain! \n";
       direction = GetDirection();
   }

   //Denali Mountain(North American)
   Mountain2(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Denali Mountain(North American)
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain2(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Denali Mountain(North American) \n";
   cout << "\nIt's unbelievably cold and is used as a training ground for the Himalayas) \n";

   water += FindWater(10);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'W' && direction != 'E'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'W')
        //Aconcagua Mountain(Highest Mountain outside of the Himalayas
        Mountain3(water, food);
    else if(direction == 'E')
        //Kosciuszko Mountain(Highest point in Australia)
        Mountain1(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Aconcagua Mountain(Highest Mountain outside of the Himalayas
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain3(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Aconcagua Mountain(Highest Mountain outside of the Himalayas) \n";
   cout << "\nThe peak rises almost 7000m into the air \n";

   water += FindWater(5);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'N' && direction != 'E'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'N')
        //Mountain Everest Mountain(Highest Mountain in the world)
        Mountain4(water, food);
    else if(direction == 'E')
        //Mountain Denali Mountain(North American)
        Mountain2(water, food);

}

//------------------------------------------------------------
// Purpose: To climb Mountain Everest Mountain(Highest Mountain in the world)
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain4(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Everest Mountain(Highest Mountain in the world) \n";
   cout << "\nNo other mountain is so instantly recognizably or has such a history surrounding it) \n";

   addFood(13, food);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'N' && direction != 'S'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'N')
        //Mountain Mount Godwin-Austen
        Mountain5(water, food);
    else if(direction == 'S')
        //Mountain Aconcagua Mountain(Highest Mountain outside of the Himalayas
        Mountain3(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Mount Godwin-Austen
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain5(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Mount Godwin-Austen \n";
   cout << "\nMount Godwin-Austen or Chhogori, has a summit 8,611 metres above sea level."
        << "It is located on the border between China and Pakistan. \n";

   water += FindWater(15);
   addFood(30, food);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'E' && direction != 'S'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'E')
        //Mountain Lhotse
        Mountain6(water, food);
    else if(direction == 'S')
        //Mountain Everest Mountain(Highest Mountain in the world)
        Mountain4(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Lhotse
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain6(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Lhotse \n";
   cout << "\nLhotse, elevation - 8,516 metres, is the fourth highest mountain in the world. \n";

   water += FindWater(35);
   addFood(30, food);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'E' && direction != 'W'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'E')
        //Mountain Makalu
        Mountain7(water, food);
    else if(direction == 'W')
        //Mountain Mount Godwin-Austen
        Mountain5(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Makalu
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain7(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Makalu \n";
   cout << "\nMakalu is notable for its summit's iconic pyramid shape. \n";

   addFood(50, food);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'S' && direction != 'W'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'S')
        //Mountain Nanga Parbat
        Mountain8(water, food);
    else if(direction == 'W')
        //Mountain Lhotse
        Mountain6(water, food);
}

//------------------------------------------------------------
// Purpose: To climb Mountain Nanga Parbat
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain8(int &water, int &food){
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Nanga Parbat \n";
   cout << "\nNanga Parbat is a notoriously dangerous hill to climb, and has been labelled the 'Killer Mountain' \n";

   water += FindWater(25);
   addFood(10, food);

   cout << "\nHealth: " << food << " water: " << water << endl;

   char direction = GetDirection();
   while(direction != 'N' && direction != 'E'){
        cout << "\nThat's not an option from this Mountain! \n";
        direction = GetDirection();
   }

   if(direction == 'N')
        //Mountain Makalu
        Mountain7(water, food);
    else if(direction == 'E')
        //Ending Mountain of the game, Vinson Massif Mountain(Located in Antarctica)
        Exit(water, food);
}

//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main() {
   // Initialize game
   int water = 50;
   int food = 100;
   srandom(time(NULL));

   // Test the mountain functions
   //Kosciuszko Mountain(Highest point in Australia)
   Mountain1(water, food);

   return 0;
}