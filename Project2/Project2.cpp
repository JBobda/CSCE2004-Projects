#include <iostream>

const float bitCoinRate = 6299.00f; // Amount of US Dollars per Bitcoin on 9/10/2018
const float ethereumRate = 196.95f; //Amount of US Dollars per Ether on 9/10/2018
const float liteCoinRate = 53.96f; //Amount of US Dollars per LiteCoin on 9/10/2018
const float bitCoinCashRate = 466.86f; //Amount of US Dollars per BitCoinCash on 9/10/2018

int main(){

    //Local Variable declaration
    std::string conversionPrefix;
    int conversionChoice = 0;
    int currencyChoice = 0;
    float currencyAmount = 0.f;

    //List of the CryptoCurrency Conversions that this program supports
    std::cout << "Welcome, this program supports the conversion of U.S Dollars to and from\n1)Bitcoin 2)Ethereum 3)LiteCoin 4)BitCoinCash" << std::endl;

    //Asking the user for input
    std::cout << "Please enter wether you want \n1)Dollars to Cryptocurrency 2)Cryptocurrency to Dollars" << std::endl;
    std::cin >> conversionChoice;

    //Error Checking to make sure that the user selects valid currency choice
    if(conversionChoice != 1 && conversionChoice != 2){
        std::cout << conversionChoice << " is an invalid input for the conversion choice."<< std::endl;
        return 0;
    }

    //If the user chooses to convert US Dollars -> Cryptocurrency
    if(conversionChoice == 1){
        std::cout << "Please enter what Cryptocurrency you would like to convert to\n1)Bitcoin 2)Ethereum 3)LiteCoin 4)BitCoinCash" << std::endl;
        std::cin >> currencyChoice;

        //Error Checking to make sure that the user selects valid currency choice
        if(currencyChoice > 4 || currencyChoice < 1){
            std::cout << currencyChoice << " is an invalid input for the currency choice" << std::endl;
            return 0;
        }

        std::cout << "Please enter the amount of US Dollars you would like to convert: " << std::endl;
        std::cin >> currencyAmount;

        //Error Checking to make sure that the user selects valid currency amount
        if(currencyAmount < 0){
            std::cout << currencyAmount << " is an invalid input for the currency amount."<< std::endl;
            return 0;
        }

        switch(currencyChoice){
            case 1:
              currencyAmount = currencyAmount / bitCoinRate;
              conversionPrefix = " BTC";
              break;
            case 2:
              currencyAmount = currencyAmount / ethereumRate;
              conversionPrefix = " ETH";
              break;
            case 3:
              currencyAmount = currencyAmount / liteCoinRate;
              conversionPrefix = " LTC";
              break;
            case 4:
              currencyAmount = currencyAmount / bitCoinCashRate;
              conversionPrefix = " BCH";
              break;
        }
        std::cout << "Your currency converts to " << currencyAmount << conversionPrefix << std::endl;
    }

    //If the user chooses to convert Cryptocurrency -> US Dollars
    else if(conversionChoice == 2){
        std::cout << "Please enter what Cryptocurrency you would like to convert to Dollars\n1)Bitcoin 2)Ethereum 3)LiteCoin 4)BitCoinCash" << std::endl;
        std::cin >> currencyChoice;

        //Error Checking to make sure that the user selects valid currency choice
        if(currencyChoice > 4 || currencyChoice < 1){
            std::cout << currencyChoice << " is an invalid input for the currency choice" << std::endl;
            return 0;
        }

        std::cout << "Please enter the amount of Cryptocurrency you would like to convert: " << std::endl;
        std::cin >> currencyAmount;

        //Error Checking to make sure that the user selects valid currency amount
        if(currencyAmount < 0){
            std::cout << currencyAmount << " is an invalid input for the currency amount."<< std::endl;
            return 0;
        }

        switch(currencyChoice){
            case 1:
              currencyAmount = currencyAmount * bitCoinRate;
              break;
            case 2:
              currencyAmount = currencyAmount * ethereumRate;
              break;
            case 3:
              currencyAmount = currencyAmount * liteCoinRate;
              break;
            case 4:
              currencyAmount = currencyAmount * bitCoinCashRate;
              break;
        }
        std::cout << "Your currency converts to $" << currencyAmount << std::endl;
    }

    return 0;
}
