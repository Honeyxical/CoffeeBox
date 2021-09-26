#include <iostream>
#include <unistd.h>

using namespace std;

int getNum(int num);

int setNum();

void installingCup();

void supplyWater();

void supplyCoffee();

void supplyMilk();

class CoffeBox {
private:
    double balance;
    int cup;
    double coin = 0;
    double costOfAmericano;
    double costOfCappuccino;
    double costOfEspresso;

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

    double depositCoin(double coin) {
        balance += coin;
        return balance;
    }

    double setCoin() {
        cout << "Put the coin in the coin receiver:";
        cin >> coin;
        return coin;
    }

    double getCoin() {
        return coin;
    }

public:

    void makeAmericano(string coffee) {
        setBalance(getBalance() - getCostOfAmericano());
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
        cout << coffee << " is being prepared!" << endl << endl;
        installingCup();
        supplyCoffee();
        cout << endl;
        cout << coffee << " is ready! Take the cup away!" << endl;
        sleep(2);
    }

public:
    CoffeBox(double balance, int cup, double costOfAmericano, double costOfCappuccino, double costOfEspresso) : balance(
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

    CoffeBox coffeBox(0, 7, 2.5, 3.5, 2);

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

        switch (getNum(setNum())) {
            case 1:
                cout
                        << "The coin receiver accepts only coins in the amount of 2 byn / 1 byn / 0.5 byn / 0.2 byn / 0.1 byn"
                        << endl;
                coffeBox.setCoin();
                coffeBox.depositCoin(coffeBox.getCoin());
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
                break;
        }
    }
}

int setNum() {
    int num;
    cin >> num;
    return num;
}

int getNum(int num) {
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