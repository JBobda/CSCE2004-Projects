#include <iostream>
#include <cmath>

//Function to check if user input is valid
void validateInput(int& variable, std::string prompt){
    while(std::cin.fail()){
            std::cout << "Wrong input" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << prompt << std::endl;
            std::cin >> variable;
    }
}

std::string specialCipher(std::string input, int shift, size_t index){
    if(index < input.length()){
        input[index] = toupper(input[index]);
        //In case they choose something outside of the alphabet
        if(input[index] >= 'A' && input[index] <= 'Z'){
            input[index] = input[index] - shift;
            //Makes sure that the shift doesn't push the value out of the alphabet
            while(input[index] < 'A')
                input[index] += 26;
        }
        //Changes the shift value after every encryption
        shift =  (shift + (2 * shift)) % 25;
        return specialCipher(input, shift, index + 1);
    }else{
        return input;
    }
}

std::string specialDecipher(std::string input, int shift, size_t index){
    if(index < input.length()){
        input[index] = toupper(input[index]);
        if(input[index] >= 'A' && input[index] <= 'Z'){
            //Standard Caesar Decipher portion here
            input[index] += shift;
            
            while(input[index] > 'Z')
                input[index] -= 26;
        }
        //Changes the shift value after every decryption
        shift =  (shift + (2 * shift)) % 25;
        return specialDecipher(input, shift, index + 1);
    }else{
        return input;
    }
}

//Recursive Caesar Cipher function
std::string recursiveCaesarCipher(std::string input, int shift, size_t index){
    if(index < input.length()){
        input[index] = toupper(input[index]);
        //In case they choose something outside of the alphabet
        if(input[index] >= 'A' && input[index] <= 'Z'){
            input[index] = input[index] - shift;

            //Makes sure that the shift doesn't push the value out of the alphabet
            while(input[index] < 'A')
                input[index] += 26;
        }

        return recursiveCaesarCipher(input, shift, index + 1);
    }else{
        return input;
    }
}

//Recursive Caesar Decipher function
std::string recursiveCaesarDecipher(std::string input, int shift, size_t index){
    if(index < input.length()){
        input[index] = toupper(input[index]);
        if(input[index] >= 'A' && input[index] <= 'Z'){
            input[index] += shift;

            while(input[index] > 'Z')
                input[index] -= 26;
        }

        return recursiveCaesarDecipher(input, shift, index + 1);
    }else{
        return input;
    }
}

//Normal Caesar Cipher function
std::string caesarCipher(std::string input, int shift){
    for(size_t i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        //In case they choose something outside of the alphabet
        if((input[i] < 65 || input[0] > 90)) continue;

        //Adds the shift 
        input[i] = input[i] - shift;
        while(input[i] < 'A')
            input[i] += 26;
    }

    return input;
}

//Normal Caesar Decipher function
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

//Main menu function for the program
void menu(std::string& userString, std::string& endString){
    int menuChoice = 0;
    int shift = 0;
    std::string prompt = "Welcome to Caesars Cipher 2.0\n"
                         "1) Encode using classic algorithm\n"
                         "2) Decode using classic algorithm\n"
                         "3) Encode using improved algorithm\n"
                         "4) Decode using improved algorithm\n"
                         "5) Exit the program\n";

    while(true){
        menuChoice = 0;
        shift = 0;
        std::cout << prompt;

        //Takes in the user's menu choice, if it is invalid or option 5, the program exits
        std::cin >> menuChoice;
        validateInput(menuChoice, prompt);
        if(menuChoice == 5){
            return;
        }else if(menuChoice >5 || menuChoice < 1){
            std::cout << "Menu choice was invalid." << std::endl;
            continue;
        }

        //Prompts the user for a shift value
        while(shift > 25 || shift < 1){
            std::cout << "Enter a shift value: " << std::endl;
            std::cin >> shift;
            validateInput(shift, "Enter a shift value: ");
        }

        switch(menuChoice){
            case 1:
                //Taking user input and then passing it into the caesar cipher function
                std::cout << "Please enter a string you would like to encrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = recursiveCaesarCipher(userString, shift, 0);
                break;
            case 2:
                //Taking user input and then passing it into the caesar decipher function
                std::cout << "Please enter a string you would like to decrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = recursiveCaesarDecipher(userString, shift, 0);
                break;
            case 3:
                //Taking user input and then passing it into the special cipher function
                std::cout << "Please enter a string you would like to encrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = specialCipher(userString, shift, 0);
                break;
            case 4:
                //Taking user input and then passing it into the special decipher function
                std::cout << "Please enter a string you would like to decrypt: " << std::endl;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, userString);
                endString = specialDecipher(userString, shift, 0);
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

    menu(userString, encryptedString);
    return 0;
}
