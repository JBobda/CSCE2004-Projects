#include <iostream>

const float goldDensity = 19.32f; //grams per cubic centimeter (g/cm^3)
const float silverDensity = 10.5f; //grams per cubic centimeter (g/cm^3)
const float steelDensity = 8.05f; //grams per cubic centimeter (g/cm^3)

int main(){
    //Defines the variables of the top
    int bigSphereRad = 0;
    int smallSphereRad = 0;
    int cylinderHeight = 0;

    //Total Volume and Area of the Top
    int totalVolume = 0;
    int totalArea = 0;

    //Takes in user input to fill the values of the declared variables
    std::cout << "Enter the Radius of the big circle: " << std::endl;
    std::cin >> bigSphereRad;
    std::cout << "Enter the Radius of the small circle: " << std::endl;
    std::cin >> smallSphereRad;
    std::cout << "Enter the Height of the cylinder: " << std::endl;
    std::cin >> cylinderHeight;

    //Prints out the total Volume and Surface Area of the Top
    std::cout << "\nResults: " << "\n";
    std::cout << "Surface Area = " << "\n";
    std::cout << "Volume = " << "\n\n";

    //Prints out the mass of the Top made out of different materials
    std::cout << "Mass: " << "\n";
    std::cout << "Gold = " << totalVolume * goldDensity << "\n";
    std::cout << "Silver = " << totalVolume * silverDensity << "\n";
    std::cout << "Steel = " << totalVolume * steelDensity << "\n";
    
    return 0;
}