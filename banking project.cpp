#include <iostream>

using namespace std;

int menu();

int main(){

    double withdrawMoney;
    double depositMoney;
    double currentBalance;

//inputs current balance
    cout << "Please enter your current balance: ";
    cin >> currentBalance;

//assigns an integer to choice
    int choice = menu();

//decides when to end the switch
    bool finish = false;

//main meat. choice = menu(); just loops back.
    while(finish == false){
        switch(choice){
            case 1:
                cout << "Your current balance is: " << currentBalance;
                choice = menu();
                break;
            case 2:{
                cout << "Please enter your deposit: ";
                cin >> depositMoney;
                //making it so that it prints out newBalance instead of currentBalance
                double newBalance = currentBalance + depositMoney;
                currentBalance = newBalance;
                cout << "Your new balance is: " << currentBalance << '\n';
                choice = menu();
                break;
            }
            case 3:{
                //defining a variable so that we don't get 2 "Please enter your withdrawal:"s
                bool i = false;
                while(i == false){
                cout << "Please enter your withdrawal: ";
                cin >> withdrawMoney;
                i = true;
                }
                if(withdrawMoney > currentBalance){
                    cout << "You do not have sufficient funds" << '\n';
                    //loops it back to the while loop
                    i = false;
                }
                else{
                    //making it so that it prints out newBalance instead of currentBalance
                    double newBalance = currentBalance - withdrawMoney;
                    currentBalance = newBalance;
                    cout << "Your new balance is: " << currentBalance << '\n';
                    choice = menu();
                }
                break;
            }
            case 4:
                cout << "Thank you for using our service.";
                finish = true;
                break;
            default:
                cout << "Invalid integer.\n";
                choice = menu();
        }
    }
    return 0;
}

int menu(){
    int number;
    cout << "Please enter an integer (1-4): \n";
    cout << "1: Show Balance\n";
    cout << "2: Deposit Money\n";
    cout << "3: Withdraw Money\n";
    cout << "4: Exit\n";
    cin >> number;
    return number;
}

