#include <iostream>

using namespace std;

int getNum();

class CoffeBox{
private:
    int balance;
    int cup;

public:
    CoffeBox(int balance, int cup) : balance(balance), cup(cup) {
        this->balance = balance;
        this->cup = cup;
    }

public:
    int getBalance(){
        return balance;
    }
    int depositCoin(int coin) {
        balance += coin;
        return balance;
    }
};

//say Hello
int main() {

    CoffeBox coffeBox(0, 7);

    while (true){

        cout << "Coffee Box. v1.0" << endl;
        cout << "Balance: " << coffeBox.getBalance() << "byn." << endl;
        cout << "1. Add money." << endl;
        cout << "2. Make Americano." << endl;
        cout << "3. Make Cappuccino." << endl;
        cout << "4. Make Espresso." << endl;
        cout << "5. Service menu." << endl;
        cout << "(c) 2021, by Hanexical, w_myslicki" << endl << endl;

        switch (getNum()) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }

    return 0;
}
