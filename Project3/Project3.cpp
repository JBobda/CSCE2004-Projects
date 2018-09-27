#include <iostream>

std::string caesarCipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;

        //Adds the shift after making sure it doesn't exceed 25
        input[i] = input[i] - shift;
        while(input[i] < 'A')
            input[i] += 26;
    }

    return input;
}

std::string caesarDecipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;

        //Adds the shift after making sure it doesn't exceed 25
        input[i] = input[i] + shift;

        //If the input + the shift is outside of the alphabet, it wraps around
        while(input[i] > 'Z')
            input[i] -= 26;
    }

    return input;
}

void menu(std::string& userString, std::string& endString){
    int menuChoice = 0;
    int shift = 0;
    while(true){
        std::cout << "Welcome to Caesars Cipher 2.0\n"
                << "1) Encode using classic algorithm\n"
                << "2) Decode using classic algorithm\n"
                << "3) Encode using improved algorithm\n"
                << "4) Decode using improved algorithm\n"
                << "5) Exit the program\n";

        //Takes in the user's menu choice, if it is invalid or option 5, the program exits
        std::cin >> menuChoice;
        if(menuChoice == 5){
            return;
        }

        //Prompts the user for a shift value
        std::cout << "Enter a shift value: " << std::endl;
        std::cin >> shift;

        switch(menuChoice){
            case 1:
                //Taking user input and then passing it into the caesar cipher function
                std::cout << "Please enter a string you would like to encrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = caesarCipher(userString, shift);
                break;
            case 2:
                //Taking user input and then passing it into the caesar decipher function
                std::cout << "Please enter a string you would like to decrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = caesarDecipher(userString, shift);
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                std::cout << "Menu choice was invalid." << std::endl;
                return;
        }

        std::cout << "\n" << endString << "\n" << std::endl;
    }
}

int main(){
    //Decleration of Variables
    std::string userString = "";
    std::string encryptedString = "";
    std::string decryptedString = "";

    menu(userString, encryptedString);
    return 0;
}
