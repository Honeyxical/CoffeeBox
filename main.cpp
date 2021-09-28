#include <iostream>
#include <unistd.h>
#include "CoffeeBox.h"

using namespace std;

int getNum();

int getNum(string message);

bool enterPin(CoffeeBox &coffeeBox);

void serviceMenu(CoffeeBox &coffeeBox);

void printServiceMenu();

void printMainMenu(CoffeeBox coffeeBox);

void printCoinMenu();

void blockCoffeeBox();

void cupCheck(int numOfCups);

int main() {

    CoffeeBox coffeeBox(0,0);

    while (!coffeeBox.isBlock() && coffeeBox.getEmptyCup() > 0) {
        printMainMenu(coffeeBox);
        switch (getNum()) {
            case 1:
                cupCheck(coffeeBox.getEmptyCup());
                printCoinMenu();
                    while (true) {
                        switch (getNum()) {
                            case 1:
                                coffeeBox.balanceReplenishment(2);
                                break;
                            case 2:
                                coffeeBox.balanceReplenishment(1);
                                break;
                            case 3:
                                coffeeBox.balanceReplenishment(0.5);
                                break;
                            case 4:
                                coffeeBox.balanceReplenishment(0.2);
                                break;
                            case 5:
                                coffeeBox.balanceReplenishment(0.1);
                                break;
                            default:
                                cout
                                        << "The coin receiver accepts only coins in the amount of 2 byn / 1 byn / 0.5 byn / 0.2 byn / 0.1 byn !"
                                        << endl << endl;
                        }
                        break;
                    }
                    break;
                case 2:
                    if (coffeeBox.getBalance() >= coffeeBox.getCostOfAmericano()) {
                        coffeeBox.makeCoffee("Americano");
                        break;
                    } else {
                        cout << "Not enough funds!" << endl;
                        sleep(2);
                        break;
                    }
                case 3:
                    if (coffeeBox.getBalance() >= coffeeBox.getCostOfCappuccino()) {
                        coffeeBox.makeCoffee("Cappuccino");
                        break;
                    } else {
                        cout << "Not enough funds!" << endl;
                        sleep(2);
                        break;
                    }
                case 4:
                    if (coffeeBox.getBalance() >= coffeeBox.getCostOfEspresso()) {
                        coffeeBox.makeCoffee("Espresso");
                        break;
                    } else {
                        cout << "Not enough funds!" << endl;
                        sleep(2);
                        break;
                    }
                case 5:
                    if (enterPin(coffeeBox)) {
                        serviceMenu(coffeeBox);
                    }
                    break;
            }

    }
    if(coffeeBox.isBlock()) {
        blockCoffeeBox();
    } else if(coffeeBox.getEmptyCup() > 0){
        cout << "There are not enough cups :(" << endl;
        blockCoffeeBox();
    }
}

void serviceMenu(CoffeeBox &coffeeBox) {
    bool exit = false;
    while (!exit) {
        printServiceMenu();
        switch (getNum("Select menu item: ")) {
            case 1:
                cout << "Balance: " << coffeeBox.getIncome() << " byn." << endl << endl;
                sleep(1);
                break;
            case 2:
                cout << "Amount of withdrawn proceeds " << coffeeBox.getIncome() << " byn." << endl;
                coffeeBox.zeroingIncome();
                sleep(1);
                break;
            case 3:
                cout << "Quantity empty cups: " << coffeeBox.getEmptyCup() << endl;
                sleep(1);
                break;
            case 4:
                coffeeBox.addCups();
                break;
            case 5:
                exit = true;
                break;
        }
    }
}

void printMainMenu(CoffeeBox coffeeBox) {
    cout << "Coffee Box. LEI700 v1.0" << endl;
    cout << "Balance: " << coffeeBox.getBalance() << " byn." << endl;
    cout << "1. Add money." << endl;
    cout << "2. Make Americano " << "(" << coffeeBox.getCostOfAmericano() << " byn)." << endl;
    cout << "3. Make Cappuccino " << "(" << coffeeBox.getCostOfCappuccino() << " byn)." << endl;
    cout << "4. Make Espresso " << "(" << coffeeBox.getCostOfEspresso() << " byn)." << endl;
    cout << "5. Service menu." << endl;
    cout << "(c) 2021, by Hanexical, w_myslicki" << endl << endl;
    cout << "Please select the menu item:";
}

void printServiceMenu() {
    cout << "Service menu: " << endl;
    cout << "1. View balance." << endl;
    cout << "2. Withdrawal of proceeds" << endl;
    cout << "3. View the number of empty cups" << endl;
    cout << "4. Add empty cups" << endl;
    cout << "5. Return to main menu" << endl << endl;
}

void printCoinMenu() {
    cout << "Select the nominal value!" << endl;
    cout << "1. 2 byn." << endl;
    cout << "2. 1 byn." << endl;
    cout << "3. 0.5 byn." << endl;
    cout << "4. 0.2 byn." << endl;
    cout << "5. 0.1 byn." << endl << endl;
    cout << "Please add a coin:";
}

bool enterPin(CoffeeBox &coffeeBox) {
    bool isPin = false;
    int filedCounter = 0;
    int servicePin = coffeeBox.getPin();
    int pin;

    while (!isPin) {
        pin = getNum("Enter service pin: ");
        if (pin > 9999) {
            cout << "Wrong password length." << endl;
        }
        filedCounter++;
        if (filedCounter == 2) {
            cout << "Last chance to enter pin. \nCoffee Box will be block." << endl;
        } else if (filedCounter == 3) {
            coffeeBox.setBlock(true);
            return false;
        }
        if (pin == servicePin) {
            isPin = true;
            return true;
        }
    }
}

// Animation.

void loadingAnimation() {
    while (true) {
        sleep(1);
        cout << "." << flush;
        sleep(1);
        cout << "." << flush;
        sleep(1);
        cout << "." << flush;
        sleep(1);
        break;
    }
}

void installingCup() {
    cout << "Installing a coffee cup";
    loadingAnimation();
    cout << endl;
}

void supplyWater() {
    cout << "Supply of boiling water";
    loadingAnimation();
    cout << endl;
}

void supplyCoffee() {
    cout << "Grinding of coffee beans";
    loadingAnimation();
    cout << endl;
}

void supplyMilk() {
    cout << "Supply hot milk";
    loadingAnimation();
    cout << endl;
}

// cin

int getNum() {
    int num;
    cin >> num;
    return num;
}

int getNum(string message) {
    cout << message;
    int num;
    cin >> num;
    return num;
}

// block

void cupCheck(int numOfCups) {
    if(numOfCups <= 5){
        cout << "Warning, cups left " << numOfCups  << "." << endl;
    }
}

void blockCoffeeBox() {
    cout << "Coffee Box Is blocked!";
    exit(1);
}
