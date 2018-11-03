#include <iostream>
#include <cstdlib>
#include <iomanip>


int findMatchingItem(std::string itemNames[], int SIZE, std::string userInput){
    for(int i = 0; i < SIZE; i++){
        if(itemNames[i] == userInput)
            return i;
    }
    return -1;
}

void printMenu(std::string itemNames[], float itemPrices[], int SIZE){
        //Printing out the formatted Menu to the user
        std::cout << std::setw(13) << std::left << "Name " << std::setw(6) << std::left <<  "Price " << "\n";
        for(int i = 0; i < SIZE; i++){
            std::cout << std::setw(13) << std::left <<  itemNames[i] << "$" << std::setw(6) << std::left << std::fixed <<  std::setprecision(2) <<  itemPrices[i] << "\n";
        }
}

void printInventory(std::string itemNames[], int itemQuantities[], int SIZE){
        std::cout << std::setw(13) << std::left << "Name " << std::setw(8) << std::left <<  "Quantity " << "\n";
        for(int i = 0; i < SIZE; i++){
            std::cout << std::setw(13) << std::left <<  itemNames[i] << std::setw(6) << std::left << itemQuantities[i] << "\n";
        }
}

void chooseSnack(std::string& customerChoice, std::string& customerName, float& totalPrice, int& amount, std::string itemNames[], float itemPrices[], int itemQuantities[], int SIZE){
    while(true){
        //Ask for the user's choice
        std::cout << "Enter name of snack (or 'pay'): ";
        std::cin >> customerChoice;

        if(customerChoice == "pay"){
            std::cout << customerName << " your order costs $" << totalPrice << std::endl;
            std::cout << "Thank you for shopping at Uber Snacks\n";
            break;
        }

        std::cout << "How many do you want? ";
        std::cin >> amount;

        //Loop through possible items and find index of matching one
        int matchingItemIndex = findMatchingItem(itemNames, SIZE, customerChoice);

        //If there is no matching index, the program will not add anything to the order
        if(matchingItemIndex == -1 || itemQuantities[matchingItemIndex] <= 0){
            std::cout << "This item is either out of stock, or was never available.\n";
            continue;
        }

        //If the amount is too great, reprompt the user
        while(amount < 0){
            std::cout << "Please enter a positive amount: ";
            std::cin >> amount;
        }

        while(amount > itemQuantities[matchingItemIndex]){
            std::cout << "That is an invalid quantity!\n";
            std::cout << "There are " << itemQuantities[matchingItemIndex] << " of " << itemNames[matchingItemIndex] << " available\n";
            std::cin >> amount;
        }

        totalPrice += itemPrices[matchingItemIndex] * amount;
        itemQuantities[matchingItemIndex] -= amount;
    }

}


int main(){
    //Declaring Size of arrays and seeding random number generator
    const int SIZE = 10;
    srand(time(NULL));

    //Declaring and initializing the arrays for the snack items
    std::string itemNames[SIZE] = 
        {"Snickers", "Chips", "Skittles", "Coke", "Fanta", "Sprite", "Hershey's", "Popcorn","Doritos", "Mountain_Dew"};
    float itemPrices[SIZE] = 
        {1.50, 2.00, 1.00, 0.99, 0.99, 0.99, 1.50, 3.00, 2.00, 0.99};
    int itemQuantities[SIZE];
    for(int i = 0; i < SIZE; i++){
        itemQuantities[i] = (rand() % (101 - 10)) + 10;
    }

    std::cout << "Welcome to the Uber Snack ordering system!\n";
    std::string customerName;
    std::string customerChoice;
    int amount;
    float totalPrice = 0.f;
    //Menu Loop
    while(true){
        
        std::cout << "Enter customer name (or 'exit'): ";
        std::cin >> customerName;

        //Exit condition of the loop
        if(customerName == "exit"){
            std::cout << "The snack inventory contains:\n";
            printInventory(itemNames, itemQuantities, SIZE);
            return 0;
        }

        //Prints the menu of available snacks out to the user
        std::cout << "We have the following snacks for sale:\n";
        printMenu(itemNames, itemPrices, SIZE);

        totalPrice = 0.f;
        amount = 0;
        chooseSnack(customerChoice, customerName, totalPrice, amount, itemNames, itemPrices, itemQuantities, SIZE);
    }
    return 0;
}