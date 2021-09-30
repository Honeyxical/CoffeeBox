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
    int cupVolume = 250;
    double costOfAmericano = 1.80;
    double costOfCappuccino = 2.30;
    double costOfEspresso = 1.80;
    int pin = 7004;
    bool block = false;

public:

    CoffeeBox(double balance, double income) : balance(balance), income(income) {
        this->balance = balance;
        this->income = income;
    }

    double getCostOfAmericano() {
        return costOfAmericano;
    }

    double getCostOfCappuccino() {
        return costOfCappuccino;
    }

    double getCostOfEspresso() {
        return costOfEspresso;
    }

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

    int getCupVolume() {
        return cupVolume;
    }

public:

    void increaseIncome(double coin) {
        income += coin;
    }

    void zeroingIncome() {
        this->income = 0;
        this->balance = 0;
    }

    void addNewCup(int numOfCup) {
        this->cup += numOfCup;
    }

    void balanceReplenishment(double coin) {
        setBalance(getBalance() + coin);
        increaseIncome(coin);
    }

    void balanceWriteOff(string nameCoffee) {
        if (nameCoffee == "Americano") {
            balance -= getCostOfAmericano();
        } else if (nameCoffee == "Cappuccino") {
            balance -= getCostOfCappuccino();
        } else if (nameCoffee == "Espresso") {
            balance -= getCostOfEspresso();
        }
    }

    void makeCoffee(string nameCoffee) {
        if (cup != 0) {
            setBlock(true);
            setCup(getEmptyCup() - 1);
            cout << nameCoffee << " is being prepared!" << endl << endl;
            installingCup();
            supplyCoffee();
            if (nameCoffee == "Americano") {
                balanceWriteOff(nameCoffee);
                supplyWater();
            } else if (nameCoffee == "Cappuccino") {
                balanceWriteOff(nameCoffee);
                supplyMilk();
            } else if (nameCoffee == "Espresso") {
                balanceWriteOff(nameCoffee);
            }
            cout << endl;
            cout << nameCoffee << " is ready! Take the cup away!" << endl << endl;
            sleep(2);
        }
        setBlock(true);
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

};

#endif //COFFEEBOX_COFFEEBOX_H