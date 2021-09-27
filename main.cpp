#include <iostream>
#include <unistd.h>
#include "CoffeeBox.h"

using namespace std;

int getNum();

bool enterPin(CoffeeBox coffeeBox);

void displayServiceMenu(CoffeeBox coffeeBox);

void blockCoffeeBox();

int main() {

    CoffeeBox coffeBox(0, 7, 2.5, 3.5, 2);

    while (true) {

        cout << "Coffee Box. v1.0" << endl;
        cout << "Balance: " << coffeBox.getBalance() << " byn." << endl;
        cout << "1. Add money." << endl;
        cout << "2. Make Americano " << "(" << coffeBox.getCostOfAmericano() << " byn)." << endl;
        cout << "3. Make Cappuccino " << "(" << coffeBox.getCostOfCappuccino() << " byn)." << endl;
        cout << "4. Make Espresso " << "(" << coffeBox.getCostOfEspresso() << " byn)." << endl;
        cout << "5. Service menu." << endl;
        cout << "(c) 2021, by Hanexical, w_myslicki" << endl << endl;
        cout << "Please select the menu item:";

        switch (getNum()) {
            case 1:
                cout
                        << "The coin receiver accepts only coins in the amount of 2 byn / 1 byn / 0.5 byn / 0.2 byn / 0.1 byn"
                        << endl;
                coffeBox.setCoin();
                coffeBox.setBalance(coffeBox.getBalance() + coffeBox.getCoin());
                coffeBox.setIncome(coffeBox.getCoin());
                break;
            case 2:
                if (coffeBox.getBalance() >= coffeBox.getCostOfAmericano()) {
                    coffeBox.makeAmericano("Americano");
                    break;
                } else {
                    cout << "Not enough funds!" << endl;
                    sleep(2);
                    break;
                }
            case 3:
                if (coffeBox.getBalance() >= coffeBox.getCostOfCappuccino()) {
                    coffeBox.makeCappuccino("Cappuccino");
                    break;
                } else {
                    cout << "Not enough funds!" << endl;
                    sleep(2);
                    break;
                }
            case 4:
                if (coffeBox.getBalance() >= coffeBox.getCostOfEspresso()) {
                    coffeBox.makeEspresso("Espresso");
                    break;
                } else {
                    cout << "Not enough funds!" << endl;
                    sleep(2);
                    break;
                }
            case 5:
                if (enterPin(coffeBox)) {
                    displayServiceMenu(coffeBox);
                } else {
                    blockCoffeeBox();
                }
                break;
        }
    }
}

int getNum() {
    int num;
    cin >> num;
    return num;
}

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

bool enterPin(CoffeeBox coffeeBox) {
    bool isPin = false;
    int filedCounter = 0;
    int pin = 0;

    while (!isPin) {
        pin = getNum("Enter service pin: ");
        if (pin > 9999) {
            cout << "Wrong password length." << endl;
        } else if (pin == coffeeBox.getPin()) {
            isPin = true;
            return true;
        }
        filedCounter++;
        if (filedCounter == 2) {
            cout << "Last chance to enter pin. \nCoffee Box will be block." << endl;
        } else if (filedCounter == 3) {
            break;
        }
    }
}

void displayServiceMenu(CoffeeBox coffeeBox) {
    int exit = 0;
    while (exit == 0) {
        cout << "Service menu: " << endl;
        cout << "1. View balance." << endl;
        cout << "2. Withdrawal of proceeds" << endl;
        cout << "3. View the number of empty cups" << endl;
        cout << "4. Add empty cups" << endl;
        cout << "5. Return to main menu" << endl << endl;

        switch (getNum("Select menu item: ")) {
            case 1:
                cout << "Balance: " << coffeeBox.getIncome() << " byn." << endl << endl;
                sleep(3);
                break;
            case 2:
                cout << "Amount of withdrawn proceeds " << coffeeBox.getIncome() << " byn." << endl;
                coffeeBox.zeroingIncome();
                sleep(3);
                break;
            case 3:
                cout << "Quantity empty cups: " << coffeeBox.getEmptyCup() << endl;
                sleep(3);
                break;
            case 4:
                coffeeBox.addCups();
                break;
            case 5:
                exit = 1;
                break;
        }
    }
}

//----------service---------------

int getNum(string message) {
    cout << message;
    int num = 0;
    cin >> num;
    return num;
}

void blockCoffeeBox() {
    cout << "Coffee Box Is blocked!";
    exit(2);
}
