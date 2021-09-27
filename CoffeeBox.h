//
// Created by Владислав on 27.09.2021.
//

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
    int cup;
    double coin = 0;
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
    double setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return balance;
    }

    double setIncome(double coin) {
        income += coin;
    }

    void zeroingIncome() {
        this->income = 0;
    }

    double getIncome() const {
        return income;
    }

    void setCoin(double coin) {
        this->coin = coin;
    }

    double getCoin() {
        return coin;
    }

    int getEmptyCup() {
        return cup;
    }

    void setCup(int numOfCup) {
        this->cup += numOfCup;
    }

    int getPin() {
        return pin;
    }

    bool isBlock() const {
        return block;
    }

    void setBlock(bool block) {
        CoffeeBox::block = block;
    }

    void businessConcepts(double coin) {
        setCoin(coin);
        setBalance(getBalance() + getCoin());
        setIncome(getCoin());
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

    void addCups() {
        cout << "There is " << getEmptyCup() << "empty cups.\nCapacity 700 cups." << endl;
        int availableCups = 700 - getEmptyCup();
        cout << "Available for replenishment: " << availableCups << " cups." << endl;
        int cups = getNum("Enter quantity of cups: ");
        if (cups <= availableCups) {
            setCup(cups);
            cout << "Completed!" << endl;
            sleep(2);
        } else {
            cout << "Error number of cups!" << endl;
        }
    }

public:
    CoffeeBox(double balance, int cup, double costOfAmericano, double costOfCappuccino, double costOfEspresso)
            : balance(
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

#endif //COFFEEBOX_COFFEEBOX_H
