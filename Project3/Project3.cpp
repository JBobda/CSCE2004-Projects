#include <iostream>

std::string caesarCipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;

        //Adds the shift after making sure it doesn't exceed 25
        input[i] = input[i] + ((shift % 25) + 1);
    }

    return input;
}

std::string caesarDecipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;

        //Adds the shift after making sure it doesn't exceed 25
        input[i] = input[i] - ((shift % 25) + 1);
    }

    return input;
}

std::string specialCipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);

        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;
    }
}

std::string specialDecipher(std::string input, int shift){}

int createShift(int startShift){
    startShift += 1;
    return startShift;
}

int main(){
    //Decleration of Variables
    std::string userString = "";
    std::string encryptedString = "";
    std::string decryptedString = "";
    int shift;

    //Taking user input and then passing it into the caeser cipher function
    std::cout << "Please enter a string you would like to encrypt: " << std::endl;
    std::getline(std::cin, userString);
    std::cout << "Enter the shift to the string: " << std::endl;
    std::cin >> shift;

    encryptedString = caesarCipher(userString, shift);
    decryptedString = caesarDecipher(encryptedString, shift);

    std::cout << encryptedString << std::endl;
    std::cout << decryptedString << std::endl;
    return 0;
}
