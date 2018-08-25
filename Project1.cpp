#include <iostream>

//Pi Constant
const float PI = 3.14159f;

//Material Densities
const float goldDensity = 19.32f; //grams per cubic centimeter (g/cm^3)
const float silverDensity = 10.5f; //grams per cubic centimeter (g/cm^3)
const float steelDensity = 8.05f; //grams per cubic centimeter (g/cm^3)

//Calculates the base to the power of its exponent
int power(int base, int exponent){
    int result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}

int main(){
    //Defines the variables of the top
    float bigSphereRad = 0.f;
    float smallSphereRad = 0.f;
    float cylinderHeight = 0.f;

    //Areas of the Top
    float bigSphereArea = 0.f;
    float smallSphereArea = 0.f;
    float cylinderArea = 0.f;
    float totalArea = 0.f;

    //Volumes of the Top
    float bigSphereVolume = 0.f;
    float smallSphereVolume = 0.f;
    float cylinderVolume = 0.f;
    float totalVolume = 0.f;
    

    //Takes in user input to fill the values of the declared variables
    std::cout << "Enter the Radius of the big circle: " << std::endl;
    std::cin >> bigSphereRad;
    std::cout << "Enter the Radius of the small circle: " << std::endl;
    std::cin >> smallSphereRad;
    std::cout << "Enter the Height of the cylinder: " << std::endl;
    std::cin >> cylinderHeight;

    //Calculates the Areas of the Top
    bigSphereArea = 4 * PI * power(bigSphereRad, 2);
    smallSphereArea = (4 * PI * power(smallSphereRad, 2))/2;
    cylinderArea = (2 * PI * cylinderHeight * smallSphereRad) 
                 + (2 * PI * power(smallSphereRad, 2));
    totalArea = bigSphereArea + smallSphereArea + cylinderArea;

    //Calculates the Volumes of the Top
    bigSphereVolume = (4 * PI * power(bigSphereRad, 3))/3;
    smallSphereVolume = ((4 * PI * power(smallSphereRad, 3))/3)/2;
    cylinderVolume = PI * cylinderHeight * power(smallSphereRad, 2);
    totalVolume = bigSphereVolume + smallSphereVolume + cylinderVolume;


    //Prints out the total Volume and Surface Area of the Top
    std::cout << "\nResults: " << "\n";
    std::cout << "Surface Area = " << totalArea << "cm^2\n";
    std::cout << "Volume = " << totalVolume << "cm^3\n\n";

    //Prints out the mass of the Top made out of different materials
    std::cout << "Mass: " << "\n";
    std::cout << "Gold = " << totalVolume * goldDensity << "g\n";
    std::cout << "Silver = " << totalVolume * silverDensity << "g\n";
    std::cout << "Steel = " << totalVolume * steelDensity << "g\n";

    return 0;
}