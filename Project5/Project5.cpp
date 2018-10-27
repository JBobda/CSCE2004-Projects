#include <iostream>
#include <cstdlib>
#include <iomanip>

int main(){
    //Declaring Size of arrays and seeding random number generator
    const int SIZE = 10;
    srand(time(NULL));

    //Declaring and initializing the arrays for the snack items
    std::string itemNames[SIZE] = 
        {"Snickers", "Chips", "Skittles", "Coke", "Fanta", "Sprite", "Hershey's", "Popcorn","Doritos", "Mountain Dew"};
    float itemPrices[SIZE] = 
        {1.50, 2.00, 1.00, 0.99, 0.99, 0.99, 1.50, 3.00, 2.00, 0.99};
    int itemQuantities[SIZE];
    for(int i = 0; i < SIZE; i++){
        itemQuantities[i] = (rand() % (101 - 10)) + 10;
    }

    //Printing out the formatted Menu to the user
    std::cout << std::setw(13) << std::left << "Name " << std::setw(6) << std::left <<  "Price " << std::setw(8) << "Quantity\n";
    for(int i = 0; i < SIZE; i++){
        std::cout << std::setw(13) << std::left <<  itemNames[i] << "$" << std::setw(6) << std::left << std::fixed <<  std::setprecision(2) <<  itemPrices[i] << " " << std::setw(8) <<   itemQuantities[i] << "\n";
    }




    return 0;
}