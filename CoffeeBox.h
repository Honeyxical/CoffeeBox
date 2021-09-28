#ifndef COFFEEBOX_COFFEEBOX_H
#define COFFEEBOX_COFFEEBOX_H

using namespace std;

int getNum(string message);

void installingCup();

void supplyCoffee();

void supplyWater();

void supplyMilk();

class CoffeeBox {
private:
    double balance = 0;
    double income = 0;
    int cup = 7;
    double costOfAmericano;
    double costOfCappuccino;
    double costOfEspresso;
    int pin = 1234;
    bool block = false;

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
    double getBalance() {
        return balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    double getIncome() {
        return income;
    }

    int getEmptyCup() {
        return cup;
    }

    void setCup(int numOfCup) {
        this->cup = numOfCup;
    }

    int getPin() {
        return pin;
    }

    bool isBlock() {
        return block;
    }

    void setBlock(bool block) {
        this->block = block;
    }

public:

    void increaseIncome(double coin) {
        income += coin;
    }

    void zeroingIncome() {
        this->income = 0;
    }

    void addNewCup(int numOfCup) {
        this->cup += numOfCup;
    }

    void balanceReplenishment(double coin) {
        setBalance(getBalance() + coin);
        increaseIncome(coin);
    }

    void makeCoffee(string nameCoffee) {
        setCup(getEmptyCup() - 1);
        cout << nameCoffee << " is being prepared!" << endl << endl;
        installingCup();
        supplyCoffee();
        if (equal(nameCoffee.begin(), nameCoffee.end(), "Americano")) {
            setBalance(getBalance() - getCostOfAmericano());
            supplyWater();
        } else if (equal(nameCoffee.begin(), nameCoffee.end(), "Cappuccino")) {
            setBalance(getBalance() - getCostOfCappuccino());
            supplyMilk();
        } else if (equal(nameCoffee.begin(), nameCoffee.end(), "Espresso")) {
            setBalance(getBalance() - getCostOfEspresso());
        }
        cout << endl;
        cout << nameCoffee << " is ready! Take the cup away!" << endl;
        sleep(2);
    }

    void addCups() {
        cout << "There is " << getEmptyCup() << "empty cups.\nCapacity 700 cups." << endl;
        int availableCups = 700 - getEmptyCup();
        cout << "Available for replenishment: " << availableCups << " cups." << endl;
        int cups = getNum("Enter quantity of cups: ");
        if (cups <= availableCups) {
            addNewCup(cups);
            cout << "Completed!" << endl;
            sleep(2);
        } else {
            cout << "Error number of cups!" << endl;
        }
    }

public:
    CoffeeBox(double balance, double costOfAmericano, double costOfCappuccino, double costOfEspresso)
            : balance(
            balance),
              costOfAmericano(
                      costOfAmericano),
              costOfCappuccino(
                      costOfCappuccino),
              costOfEspresso(
                      costOfEspresso) {
        this->balance = balance;
        this->costOfAmericano = costOfAmericano;
        this->costOfCappuccino = costOfCappuccino;
        this->costOfEspresso = costOfEspresso;
    }
};

#endif //COFFEEBOX_COFFEEBOX_H
