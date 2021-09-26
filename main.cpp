#include <iostream>
#include <unistd.h>

using namespace std;

class CoffeeBox;

int getNum();

int getNum(string message);

void installingCup();

void supplyWater();

void supplyCoffee();

void supplyMilk();

bool enterPin(CoffeeBox coffeeBox);

void displayServiceMenu(CoffeeBox coffeeBox);

void blockCoffeeBox();

class CoffeeBox {
private:
    double balance;
    double income;
    int cup;
    double coin = 0;
    double costOfAmericano;
    double costOfCappuccino;
    double costOfEspresso;
    int pin = 1234;

public:
    double getCostOfAmericano() {
        return costOfAmericano;
    }

    double getCostOfCappuccino() {
        return costOfCappuccino;
    }

    double getCostOfEspresso() {
        return costOfEspresso;
    }

public:
    double setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return balance;
    }

    double setIncome(double coin) {
        income += coin;
        return income;
    }

    void zeroingIncome(){
        this->income = 0;
    }

    double getIncome() const {
        return income;
    }

    double setCoin() {
        cout << "Put the coin in the coin receiver:";
        cin >> coin;
        return coin;
    }

    double getCoin() {
        return coin;
    }

    int getEmptyCup(){
        return cup;
    }

    void setCup(int numOfCup){
        this->cup += numOfCup;
    }

    int getPin(){
        return pin;
    }

public:

    void makeAmericano(string coffee) {
        setBalance(getBalance() - getCostOfAmericano());
        setCup(getEmptyCup() - 1);
        cout << coffee << " is being prepared!" << endl << endl;
        installingCup();
        supplyCoffee();
        supplyWater();
        cout << endl;
        cout << coffee << " is ready! Take the cup away!" << endl;
        sleep(2);
    }

    void makeCappuccino(string coffee) {
        setBalance(getBalance() - getCostOfCappuccino());
        setCup(getEmptyCup() - 1);
        cout << coffee << " is being prepared!" << endl << endl;
        installingCup();
        supplyCoffee();
        supplyWater();
        supplyMilk();
        cout << endl;
        cout << coffee << " is ready! Take the cup away!" << endl;
        sleep(2);
    }

    void makeEspresso(string coffee) {
        setBalance(getBalance() - getCostOfEspresso());
        setCup(getEmptyCup() - 1);
        cout << coffee << " is being prepared!" << endl << endl;
        installingCup();
        supplyCoffee();
        cout << endl;
        cout << coffee << " is ready! Take the cup away!" << endl;
        sleep(2);
    }

    void addCups(){
        cout << "There is " << getEmptyCup() << "empty cups.\nCapacity 700 cups." << endl;
        int availableCups = 700 - getEmptyCup();
        cout << "Available for replenishment: " << availableCups << " cups." << endl;
        int cups = getNum("Enter quantity of cups: ");
        if (cups <= availableCups){
            setCup(cups);
            cout << "Completed!" << endl;
            sleep(2);
        } else{
            cout << "Error number of cups!" << endl;
        }
    }

public:
    CoffeeBox(double balance, int cup, double costOfAmericano, double costOfCappuccino, double costOfEspresso) : balance(
            balance), cup(cup),
                                                                                                                costOfAmericano(
                                                                                                                        costOfAmericano),
                                                                                                                costOfCappuccino(
                                                                                                                        costOfCappuccino),
                                                                                                                costOfEspresso(
                                                                                                                        costOfEspresso) {
        this->balance = balance;
        this->cup = cup;
        this->costOfAmericano = costOfAmericano;
        this->costOfCappuccino = costOfCappuccino;
        this->costOfEspresso = costOfEspresso;
    }
};

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
                cout << "The coin receiver accepts only coins in the amount of 2 byn / 1 byn / 0.5 byn / 0.2 byn / 0.1 byn" << endl;
                coffeBox.setBalance(coffeBox.getBalance() + coffeBox.setCoin());
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
                if(enterPin(coffeBox)){
                    displayServiceMenu(coffeBox);
                } else{
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



bool enterPin(CoffeeBox coffeeBox){
    bool isPin = false;
    int filedCounter = 0;
    int pin = 0;

    while (!isPin){
        pin = getNum("Enter service pin: ");
        if(pin > 9999){
            cout << "Wrong password length." << endl;
        } else if(pin == coffeeBox.getPin()){
            isPin = true;
            return true;
        }
        filedCounter++;
        if (filedCounter == 2){
            cout << "Last chance to enter pin. \nCoffee Box will be block." << endl;
        } else if (filedCounter == 3){
            break;
        }
    }
}

void displayServiceMenu(CoffeeBox coffeeBox){
    int exit = 0;
    while (exit == 0){
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

int getNum(string message){
    cout << message;
    int num = 0;
    cin >> num;
    return num;
}

void blockCoffeeBox(){
    cout << "Coffee Box Is blocked!";
    exit(2);
}
