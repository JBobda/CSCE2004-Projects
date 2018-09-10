#include <iostream>

const float bitCoinRate = 6299.00f; // Amount of US Dollars per Bitcoin 9/10
const float ethereumRate = 196.95f; //Amount of US Dollars per Ether 9/10
const float liteCoinRate = 53.96f; //Amount of US Dollars per LiteCoin 9/10
const float bitCoinCashRate = 466.86f; //Amount of US Dollars per BitCoinCash 9/10

int main(){

    //Local Variable declaration
    int conversionChoice = 0;
    int currencyChoice = 0;
    float currencyAmount = 0.f;

    //Asking the user for input
    std::cout << "Please enter wether you want \n1)Dollars to Cryptocurrency 2)Cryptocurrency to Dollars" << std::endl;
    std::cin >> conversionChoice;

    //If the user chooses to convert US Dollars -> Cryptocurrency
    if(conversionChoice == 1){
        std::cout << "Please enter what Cryptocurrency you would like to convert to\n1)Bitcoin 2)Ethereum 3)LiteCoin 4)BitCoinCash" << std::endl;
        std::cin >> currencyChoice;
        std::cout << "Please enter the amount of US Dollars you would like to convert: " << std::endl;
        std::cin >> currencyAmount;

        switch(currencyChoice){
            case 1:
              currencyAmount = currencyAmount / bitCoinRate;
              break;
            case 2:
              currencyAmount = currencyAmount / ethereumRate;
              break;
            case 3:
              currencyAmount = currencyAmount / liteCoinRate;
              break;
            case 4:
              currencyAmount = currencyAmount / bitCoinCashRate;
              break;
        }
        std::cout << "Your currency is " << currencyAmount << std::endl;
    }

    //If the user chooses to convert Cryptocurrency -> US Dollars
    else if(conversionChoice == 2){
        std::cout << "Please enter what Cryptocurrency you would like to convert to Dollars\n1)Bitcoin 2)Ethereum 3)LiteCoin 4)BitCoinCash" << std::endl;
        std::cin >> currencyChoice;
        std::cout << "Please enter the amount of Cryptocurrency you would like to convert: " << std::endl;
        std::cin >> currencyAmount;

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
        std::cout << "Your currency is " << currencyAmount << std::endl;
    }

    return 0;
}
